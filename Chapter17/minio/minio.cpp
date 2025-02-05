#include <miniocpp/client.h>
#include <spdlog/spdlog.h>

#include <sole.hpp>
#include <string>

std::string access_key = "Q3AM3UQ867SPQQA43P2F";
std::string secret_key = "zuf+tfteSlswRu7BJ86wekitnifILbZam1KYY3TG";

bool create_user_bucket(const std::string& username) {
  minio::s3::BaseUrl base_url("play.min.io");
  minio::creds::StaticProvider provider(access_key, secret_key);

  minio::s3::Client client(base_url, &provider);

  std::string unique_prefix = sole::uuid4().str();
  std::string bucket_name{"user-bucket-" + username};
  std::string full_name{unique_prefix + bucket_name};

  minio::s3::MakeBucketArgs args;
  args.bucket = full_name;

  if (const minio::s3::MakeBucketResponse resp = client.MakeBucket(args)) {
    spdlog::info("{} bucket is created successfully", args.bucket);
  } else {
    spdlog::error("Unable to create bucket {}: {}", args.bucket,
                  resp.Error().String());
    return false;
  }

  return true;
}

int main() {
  if (const std::string username = "random-42"; create_user_bucket(username)) {
    spdlog::info("The bucket for {} is ready", username);
  }

  return 0;
}
