/*

Copyright 2019 Peter Asanov

Permission is hereby granted, free of charge,
to any person obtaining a copy of this software and associated documentation files( the "Software"),
to deal in the Software without restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and / or sell copies of the Software,
and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or
substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

*/

#pragma once

#include "mpegts.h"

#include <memory>
#include <string>

#include <boost/asio/io_context.hpp>

namespace mpegts
{
class demux_service
{
public:
  explicit demux_service(const std::string &file_name,
      boost::asio::io_context &signal_listening_context, packet_received_callback_t callback);
  ~demux_service();
  demux_service(const demux_service &) = delete;
  demux_service &operator=(const demux_service &) = delete;

  void start();
  void stop();
  void join();
  void reset();

private:
  class impl;
  std::unique_ptr<impl> _impl;
};
} // namespace mpegts
