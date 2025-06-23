#include <aws/core/Aws.h>
#include <aws/core/utils/UUID.h>
#include <aws/s3/S3Client.h>
#include <aws/s3/model/CreateBucketRequest.h>
#include <spdlog/spdlog.h>

#include <string>

constexpr auto region = Aws::S3::Model::BucketLocationConstraint::eu_central_1;

bool create_user_bucket(const std::string& username) {
  Aws::S3::Model::CreateBucketRequest request;

  const Aws::String unique_prefix = Aws::Utils::UUID::RandomUUID();

  const Aws::String bucket_name("user-bucket-" + username);
  const Aws::String full_name = unique_prefix + bucket_name;
  request.SetBucket(Aws::Utils::StringUtils::ToLower(full_name.c_str()));

  Aws::S3::Model::CreateBucketConfiguration bucket_config;
  bucket_config.SetLocationConstraint(region);
  request.SetCreateBucketConfiguration(bucket_config);

  const Aws::S3::S3Client s3_client;

  if (const auto outcome = s3_client.CreateBucket(request);
      !outcome.IsSuccess()) {
    const auto& err = outcome.GetError();
    spdlog::error("ERROR:  CreateBucket:  {}:  {}", err.GetExceptionName(),
                  err.GetMessage());
    return false;
  }

  return true;
}

int main() {
  const std::string username = "random-42";

  const Aws::SDKOptions options;
  Aws::InitAPI(options);

  if (create_user_bucket(username)) {
    std::cout << "The bucket for " << username << " is ready" << std::endl;
  }

  ShutdownAPI(options);
}
