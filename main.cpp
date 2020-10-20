#include <iostream>
#include <getopt.h>
#include <stdlib.h>
#include <stdio.h>
#include <curl/curl.h>
using namespace std;

int main(int argc, char** argv)
{
  char *url;
  int profile = 5;
  int c;

  struct option longopts[] = {
    { "url",     required_argument, NULL, 'u'},
    { "profile", required_argument, NULL, 'p'},
    { "help",    no_argument,       NULL, 'h'},
    { 0, 0, 0, 0 }
  };
  
  while ((c = getopt_long(argc, argv, ":u:p:h", longopts, NULL)) != -1) {
      switch (c) {
        case 'u':
          url = optarg;
          break;
        case 'p':
          profile = atoi(optarg);
          break;
        case 'h':
          printf("Usage: main [OPTION]...\n");
          printf("Example: main --url www.google.com --profile 5\n");
          printf("Options:\n");
          printf("\t-u, --url\t[REQUIRED] Specify a url to test\n");
          printf("\t-p, --profile\tNumber of requests to make to the url. Defaults to 5\n");
          printf("\t-h, --url\tPrint help\n");
          exit(0);
        case '?':
          if(isprint(optopt)){
            printf("Option -%c is not a valid option\n", optopt);
          } else {
            printf("Option \\x%x is not a valid option\n", optopt);
          }
          break;
        case ':':
          printf("Option -%c requires an argument\n", optopt);
          break;
        default:
          exit(0);
    }
  }
  if(!url[0]){
    printf("Parameter -u [--url] is required\n");
    exit(0);
  }
  for(int i = 0; i < profile; i++){
    CURL *curl;
    CURLcode res;
    struct string s;
    init_string(&s);
  
    curl = curl_easy_init();
    if(curl) {
      curl_easy_setopt(curl, CURLOPT_URL, url);
      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
      curl_easy_setopt(curl, CURLOPT_WRITEDATA, &s);
      res = curl_easy_perform(curl);
      if(res != CURLE_OK){
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
      }
      else {
        printf("\n HELLO: %s\n", s);
      }
      curl_easy_cleanup(curl);
    }
  }

  return 0;
}