// Navigation pane project template
#ifndef GameInThePhone_HPP_
#define GameInThePhone_HPP_

#include <QObject>
#include "mongoose.h"
namespace bb { namespace cascades { class Application; }}

/*!
 * @brief Application pane object
 *
 *Use this object to create and init app UI, to create context objects, to register the new meta types etc.
 */
class GameInThePhone : public QObject
{
    Q_OBJECT
public:
    //int move;
    struct mg_context *ctx;
    struct mg_callbacks callbacks;

    //static int begin_request_handler(struct mg_connection *conn);
    GameInThePhone(bb::cascades::Application *app);
    static void websocket_ready_handler(struct mg_connection *conn);
    static int websocket_data_handler(struct mg_connection *conn, int flags,char *data, size_t data_len);
    virtual ~GameInThePhone() { if(ctx) stopWS();}
    Q_INVOKABLE
    void startWS();
    Q_INVOKABLE
    void stopWS();
    Q_INVOKABLE
    void moveRight();
    Q_INVOKABLE
    void moveLeft();
    Q_INVOKABLE
    void fire();
    Q_INVOKABLE
    void release();
    static struct mg_connection *conn_;
private:

};

//mg_connection *conn_ = NULL;
#endif /* GameInThePhone_HPP_ */
