#include "String.h"

#include <cstdarg>
#include <cstdio>
#include <iostream>
#include <sys/_types/_size_t.h>
#include <vector>

namespace util::string {
std::string FormatString(int max_buffer, const char *format, ...) {
  va_list vl;
  va_start(vl, format);
  char buffer[max_buffer];

  vsnprintf(buffer, max_buffer, format, vl);

  return buffer;
}

const int kDefaultMaxBuffer = 1000;

std::string FormatString(const char *format, ...) {
  va_list vl;
  va_start(vl, format);

  char buffer[kDefaultMaxBuffer];

  vsnprintf(buffer, kDefaultMaxBuffer, format, vl);
  return buffer;
}

std::string Join(const std::vector<std::string> &strs,
                 const std::string &delim) {
  if (strs.empty())
    return "";
  std::string ret = "";
  size_t sz = strs.size();
  for (int i = 0; i < sz - 1; ++i) {
    ret = ret + strs[i] + delim;
  }
  ret = ret + strs.back();
  return ret;
}

} // namespace util::string
