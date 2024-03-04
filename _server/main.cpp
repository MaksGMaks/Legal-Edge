#include <iostream>
#include "network/HttpServer.cpp"

int main()
{
    setlocale(LC_ALL, "ru");
    // try
    // {
    //     std::locale::global(std::locale("ru_RU.utf-8"));
    // }
    // catch (const std::exception &e)
    // {
    //     std::cerr << "Exception: " << e.what() << std::endl;
    //     return 1;
    // }
    std::cout << "проверка" << std::endl;
    const std::string addr{"127.0.0.1"};
    const unsigned short int port = 8080;
    std::thread t1([&]()
                   { HttpServer server(addr, port);
                    server.run(); });
    std::cout << "after exemple of class" << std::endl;
    std::string addr = "127.0.0.1";
    HttpServer server(addr, 8080);
    // listen
    // server.test();
    std::cout << "Hello, world" << std::endl;
    t1.join();
    return 0;
}