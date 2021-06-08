#include <stdio.h>
#include <curl/curl.h>

int main(void)
{
  CURL *curl;
CURLcode res;

curl_global_init(CURL_GLOBAL_DEFAULT);

curl = curl_easy_init();
if (curl) {
  curl_easy_setopt(
      curl, CURLOPT_URL,
      "https://api.binance.com/api/v1/ticker/price?symbol=USDTBRL");

#ifdef SKIP_PEER_VERIFICATION
  curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
#endif

#ifdef SKIP_HOSTNAME_VERIFICATION
  curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
#endif

  res = curl_easy_perform(curl);

  if (res != CURLE_OK) {
    fprintf(stderr, "curl_easy_perform() failed: %s\n",
            curl_easy_strerror(res));
  }

  curl_easy_cleanup(curl);

}

curl_global_cleanup();

return 0;
}
