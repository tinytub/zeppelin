/*
 * "Copyright [2016] qihoo"
 * "Author <hrxwwd@163.com>"
 */
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#include "include/zp_cluster.h"


void usage() {
  std::cout << "usage:\n"
            << "      zp_cli host port\n";
}

int main(int argc, char* argv[]) {
  if (argc != 3) {
    usage();
    return -1;
  }

  // client handle io operation
  std::cout << "create client" << std::endl;
  libzp::Client* client = new libzp::Client(argv[1], atoi(argv[2]), "tab");
  std::cout << "connect cluster" << std::endl;
  // needs connect to cluster first
  libzp::Status s = client->Connect();
  /* operation
  s = cluster->CreateTable("test", 24);
  */
  if (!s.ok()) {
    std::cout << s.ToString() << std::endl;
    return -1;
  }
  while (true) {
    s = client->Set("key", "value");
    if (!s.ok()) {
      std::cout << s.ToString() << std::endl;
    } else {
      std::cout << "set ok" << std::endl;
    }
    usleep(10000);
  }
  delete client;
}
