#include "main.hpp"

using namespace boost::asio;
using namespace boost::asio::ip;
using namespace boost::system;



#define HOST "google.com"
#define PORT "3333"


/**
 connect a socket to a specific server application
 designated by an endpoint when an IP address and
 a protocol port number
 */
auto main (int argc, char** argv) -> int 
{
    try
    {
        
    }
    
    catch (system_error& e)
    {
        std::cout << "Error occured! Error code = " << e.code()
        << ". Message: " << e.what();
        return e.code().value();
    }
    
    auto ios = io_service {};
    auto error = error_code {};
    
    auto dns_query = tcp::resolver::query {HOST, PORT, tcp::resolver::query::numeric_service};
    auto dns_resolver = tcp::resolver {ios};
    
    //    auto protocol = tcp::v4 ();
    //    auto socket = tcp::socket {ios, protocol};
    
    /**
     Resolve a dns name
     */
    auto endpoints_begin = dns_resolver.resolve (dns_query, error);
    
    /**
     handle dns errors
     */
    if (error)
    {
        // Failed to resolve the DNS name.
        std::cout
        << "Failed to resolve a DNS name."
        << "Error code = " << error.value()
        << ". Message = " << error.message();
        
        throw;
    }
    
    
    /**
     creating a socket
     */
    auto socket = tcp::socket {ios};
    
    /**
     connect to one working endpoint
     */
    connect (socket, endpoints_begin);
    
    
    /**
     iterate over each endpoint
     */
    for (; endpoints_begin != tcp::resolver::iterator {}; ++endpoints_begin)
    {
        /**
         endpoint class designating the
         target server application to
         which we are going to connect.
         */
        auto server_endpoint = endpoints_begin -> endpoint ();
        
        
        
        /**
         opening the socket
         */
        socket.open (server_endpoint.protocol (), error);
        
        /**
         handle socket-openings errors
         */
        if (error.value() != 0)
        {
            // Failed to open the socket.
            std::cout
            << "Failed to open the socket! Error code = "
            << error.value() << ". Message: " << error.message();
            return error.value();
        }
        
        /**
         connecting the socket to the server endpoint
         */
        socket.connect (server_endpoint);
        
        
        /**
         At this point socket 'sock' is connected to
         the server application and can be used
         to send data to or receive data from it.
         */
    }
    
    
    
    
    
    
    
    
    
    
    return 0;
    
    //    auto ip_address = address::from_string ("127.0.0.1");
    //    auto endpoint = tcp::endpoint {ip_address, 3333};
}




