// Navigation pane project template
#include "GameInThePhone.hpp"

#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>
#define USE_WEBSOCKET 1
using namespace bb::cascades;
mg_connection * GameInThePhone::conn_ = NULL;
GameInThePhone::GameInThePhone(bb::cascades::Application *app)
: QObject(app) /*, move(0)*/
{

    QmlDocument *qml = QmlDocument::create("asset:///main.qml").parent(this);
    AbstractPane *root = qml->createRootObject<AbstractPane>();
    memset(&callbacks, 0, sizeof(callbacks));

    callbacks.websocket_ready = websocket_ready_handler;
    callbacks.websocket_data = websocket_data_handler;

    qml->setContextProperty("cpp", this);
    app->setScene(root);
    startWS();
}


void GameInThePhone::
websocket_ready_handler(struct mg_connection *conn) {
  unsigned char buf[40];
  GameInThePhone::conn_ = conn;
  buf[0] = 0x81;
  buf[1] = snprintf((char *) buf + 2, sizeof(buf) - 2, "%s", "server ready");
  mg_write(conn, buf, 2 + buf[1]);
}


void GameInThePhone::
release() {
	  int data_len = 7;
	  unsigned char reply[data_len+2];

	  // Prepare frame
	  reply[0] = 0x81;  // text, FIN set
	  reply[1] = data_len;
	  memcpy(reply+2,"release",data_len);
	  mg_write(conn_, reply, 2 + data_len);
	return;
}

void GameInThePhone::
moveRight() {
	  int data_len = 5;
	  unsigned char reply[data_len+2];

	  // Prepare frame
	  reply[0] = 0x81;  // text, FIN set
	  reply[1] = data_len;
	  memcpy(reply+2,"right",data_len);
	  mg_write(conn_, reply, 2 + data_len);
	  return;
}


void GameInThePhone::
moveLeft() {
	  int data_len = 4;
	  unsigned char reply[data_len+2];
	  // Prepare frame
	  reply[0] = 0x81;  // text, FIN set
	  reply[1] = data_len;
	  memcpy(reply+2,"left",data_len);
	  mg_write(conn_, reply, 2 + data_len);
	  return;
}

void GameInThePhone::
fire() {
	  int data_len = 4;
	  unsigned char reply[data_len+2];

	  // Prepare frame
	  reply[0] = 0x81;  // text, FIN set
	  reply[1] = data_len;
	  memcpy(reply+2,"fire",data_len);
	  mg_write(conn_, reply, 2 + data_len);
	  return;
}


int GameInThePhone::
websocket_data_handler(struct mg_connection *conn, int flags,char *data, size_t data_len) {
	return 1;
}


void
GameInThePhone::startWS() {
	qDebug() << "Starting ...";
	const char *options[] = {"listening_ports", "8080",
			  "document_root", "app/native/assets/www",NULL};
	ctx = mg_start(&callbacks, NULL, options);
}

void
GameInThePhone::stopWS() {
	qDebug() << "Stopping ...";
	mg_stop(ctx);
}
