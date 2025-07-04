#include <filesystem>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

struct IDocument {
  virtual ~IDocument() = default;

  virtual std::vector<std::string> extract_text() = 0;
};

class PdfDocument final : public IDocument {
public:
  explicit PdfDocument(const std::string &path) {}
  std::vector<std::string> extract_text() override { return {"Text from PDF"}; }
};

class HtmlDocument final : public IDocument {
public:
  explicit HtmlDocument(const std::string &path) {}
  std::vector<std::string> extract_text() override {
    return {"Text from HTML"};
  }
};

class OdtDocument final : public IDocument {
public:
  explicit OdtDocument(const std::string &path) {}
  std::vector<std::string> extract_text() override { return {"Text from ODT"}; }
};

std::unique_ptr<IDocument> open(const std::string &path) {
  const auto extension = std::filesystem::path(path).extension();
  if (extension == ".pdf")
    return std::make_unique<PdfDocument>(path);
  if (extension == ".html")
    return std::make_unique<HtmlDocument>(path);

  return nullptr;
}

class DocumentOpener final {
public:
  using DocumentType = std::unique_ptr<IDocument>;
  using ConcreteOpener = DocumentType (*)(const std::string &);
  // using ConcreteOpener = std::function<DocumentType(const std::string&)>;

  void register_plugin(const std::string &extension,
                       const ConcreteOpener &opener) {
    openerByExtension.emplace(extension, opener);
  }

  DocumentType open(const std::string &path) const {
    if (const auto p = std::filesystem::path(path); p.has_extension()) {
      return openerByExtension.at(p.extension().string())(path);
    }
    throw std::invalid_argument{"Trying to open a file with no extension"};
  }

private:
  std::unordered_map<std::string, ConcreteOpener> openerByExtension;
};

int main() {
  auto document_opener = DocumentOpener{};
  document_opener.register_plugin(
      ".pdf", [](const auto &path) -> DocumentOpener::DocumentType {
        return std::make_unique<PdfDocument>(path);
      });
  document_opener.register_plugin(
      ".html", [](const auto &path) -> DocumentOpener::DocumentType {
        return std::make_unique<HtmlDocument>(path);
      });
  document_opener.register_plugin(
      ".odt", [](const auto &path) -> DocumentOpener::DocumentType {
        return std::make_unique<OdtDocument>(path);
      });

  const auto document = document_opener.open("file.odt");
  std::cout << document->extract_text().front();
}
