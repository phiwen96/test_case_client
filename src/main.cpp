#include "main.hpp"






auto main (int argc, char** argv) -> int 
{
    auto i = IP_v <4>;
    
    std::cout << "hello world" << std::endl;
    
    addrinfo hints
    {
        .ai_family = AF_UNSPEC,
        .ai_socktype = SOCK_STREAM,
        .ai_flags = AI_PASSIVE
    };
    
    addrinfo *res;
    
    if (int err = getaddrinfo (nullptr, "3490", &hints, &res); err != 0)
    {
        fprintf (stderr, "getaddrinfo error: %s\n", gai_strerror (err));
        exit (1);

    }
    
    
    freeaddrinfo (res);
}




