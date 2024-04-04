#include "HttpServer.hpp"

#include <winsock2.h>
#include <ws2tcpip.h>

#include <chrono>
#include <string>

#define MAX_THREADS (std::thread::hardware_concurrency()) * 2

HttpServer::HttpServer(std::string addr,
                       unsigned short port,
                       const std::string &db_path,
                       const std::string &script) : m_ioc{1},
                                                    m_acc{m_ioc, net::ip::tcp::endpoint(net::ip::make_address(addr), static_cast<net::ip::port_type>(port))},
                                                    dbPath{std::move(db_path)},
                                                    dbScript{std::move(script)},
                                                    m_thrpool{std::make_unique<ThreadPool>(MAX_THREADS)}
{
    m_dbManager = std::make_shared<DatabaseManager>(dbPath, dbScript);
    m_dbManager->start();
    std::cout << "constructor HttpSession" << std::endl;
    try
    {
        do_accept();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void HttpServer::run()
{
    m_ioc.run();
}

void HttpServer::do_accept()
{
    std::cout << "listen ..." << std::endl;
    m_sock = boost::make_shared<net::ip::tcp::socket>(m_ioc);
    m_acc.accept(*m_sock);
    std::cout << "connecting" << std::endl;

    // idk, but this connection doesent work at 2nd connection from client
    m_thrpool->enqueue([this]
                       { on_accept(std::move(m_ec), std::move(m_sock)); });
    std::cout << "after calling method on_accept into threadpool, id -- " << std::this_thread::get_id() << std::endl;
    do_accept();
}

void HttpServer::on_accept(boost::system::error_code ec, boost::shared_ptr<net::ip::tcp::socket> sock)
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "heard, id -- " << std::this_thread::get_id() << std::endl;

    auto t = std::make_shared<HttpTransaction>(std::move(sock),
                                               std::make_unique<JsonSerializer>(),
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
                                               std::move(m_dbManager));
=======
                                               std::move(dbPath),
                                               std::move(dbScript));
>>>>>>> 04991a2 (implement database and connect it with modules and repos)
=======
                                               std::move(m_dbManager));
>>>>>>> 44d4a42 (replacing template with strategy pattern)
=======
                                               m_dbManager);
>>>>>>> d439f05 (rewrite)
    t->start();
}