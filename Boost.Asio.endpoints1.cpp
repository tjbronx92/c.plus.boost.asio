/*
Boost.Asio C++ Network Programing Cookboook
CHAPTER 1: The Basics - Creating an endpoint
*/

#include <boost/asio.hpp>
#include <iostreams>

using namespace boost;

int main()
{

// Step 1: Assume that the client has already obtained IP & Port #
  std::string raw_ip_address = "127.0.0.1";
  unsigned short port_num = 3333;

  //Stores info about errors while parsing the raw IP address
  boost::system::error_code ec;

  //Step 2:
  //Declare what IP protocol is in use (IPv4, IPv6, or both)
  //Variable ip_address can accept "both"

  asio::ip::address ip_address = asio::ip::make_address(raw_ip_address, ec);

    if(ec.value() !=0) {
      std::cout << "Failed to parse the IP addres. Error code = " << ec.value() << ". Message: " << ec.message();
        return ec.value();
    }

    asio::ip::tcp::endpoint ep(ip_address, port_num);

    return 0;

}
