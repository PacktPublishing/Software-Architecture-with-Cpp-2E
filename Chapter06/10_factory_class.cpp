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

class PdfDocument : public IDocument {
 public:
  explicit PdfDocument(std::string_view path) {}
  std::vector<std::string> extract_text() override { return {"Text from PDF"}; }
};

class HtmlDocument : public IDocument {
 public:
  explicit HtmlDocument(std::string_view path) {}
  std::vector<std::string> extract_text() override {
    return {"Text from HTML"};
  }
};

class OdtDocument : public IDocument {
 public:
  explicit OdtDocument(std::string_view path) {}
  std::vector<std::string> extract_text() override { return {"Text from ODT"}; }
};

std::unique_ptr<IDocument> open(std::string_view path) {
  const auto extension = std::filesystem::path(path).extension();
  if (extension == ".pdf") return std::make_unique<PdfDocument>(path);
  if (extension == ".html") return std::make_unique<HtmlDocument>(path);

  return nullptr;
}

class DocumentOpener {
 public:
  using DocumentType = std::unique_ptr<IDocument>;
  using ConcreteOpener = DocumentType (*)(std::string_view);
  //  using ConcreteOpener = std::function<DocumentType(std::string_view)>;

  void register_plugin(std::string_view extension, ConcreteOpener opener) {
    openerByExtension.emplace(extension, opener);
  }

  DocumentType open(std::string_view path) {
    if (const auto p = std::filesystem::path(path); p.has_extension()) {
      return openerByExtension.at(p.extension().string())(path);
    }
    throw std::invalid_argument{"Trying to open a file with no extension"};
  }

 private:
  std::unordered_map<std::string_view, ConcreteOpener> openerByExtension;
};

int main() {
  auto document_opener = DocumentOpener{};
  document_opener.register_plugin(
      ".pdf", [](auto path) -> DocumentOpener::DocumentType {
        return std::make_unique<PdfDocument>(path);
      });
  document_opener.register_plugin(
      ".html", [](auto path) -> DocumentOpener::DocumentType {
        return std::make_unique<HtmlDocument>(path);
      });
  document_opener.register_plugin(
      ".odt", [](auto path) -> DocumentOpener::DocumentType {
        return std::make_unique<OdtDocument>(path);
      });

  auto document = document_opener.open("file.odt");
  std::cout << document->extract_text().front();
}
