#ifndef ZP_SYNC_CONN_H
#define ZP_SYNC_CONN_H

#include "zp_command.h"

#include "pb_conn.h"
#include "pink_thread.h"

class ZPBinlogReceiverThread;

class ZPSyncConn: public pink::PbConn {
 public:

  ZPSyncConn(int fd, std::string ip_port, pink::Thread *thread);
  virtual ~ZPSyncConn();
  virtual int DealMessage();

 private:

  client::SyncRequest request_;

  ZPBinlogReceiverThread* self_thread_;
};

#endif
