////////////////////////////////////////////////////////////////////////////////
//
// Copyright 2010 - 2018, Göteborg Bit Factory.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
// http://www.opensource.org/licenses/mit-license.php
//
////////////////////////////////////////////////////////////////////////////////

#ifndef INCLUDED_TASKD
#define INCLUDED_TASKD

#include <algorithm>
#include <vector>
#include <string>
#include <ConfigFile.h>
#include <Msg.h>
#include <Log.h>
#include <FS.h>
#include <Database.h>

void command_init     (Database&                                  );
void command_config   (Database&, const std::vector <std::string>&);
void command_status   (                                           );
void command_help     (           const std::vector <std::string>&);
void command_diag     (Database&                                  );
void command_server   (Database&                                  );
void command_add      (Database&, const std::vector <std::string>&);
void command_remove   (Database&, const std::vector <std::string>&);
void command_suspend  (Database&, const std::vector <std::string>&);
void command_resume   (Database&, const std::vector <std::string>&);
void command_api      (Database&, const std::vector <std::string>&);
void command_validate (           const std::vector <std::string>&);

// api.cpp
bool taskd_applyOverride (Config&, const std::string&);
void taskd_requireSetting (Config&, const std::string&);
void taskd_requireVersion (const Msg&, const std::string&);
void taskd_requireHeader (const Msg&, const std::string&, const std::string&);
bool taskd_at_least (const std::string&, const std::string&);
bool taskd_createDirectory (Directory&, bool);

bool taskd_sendMessage (Config&, const std::string&, const Msg&, Msg&);
void taskd_renderMap (const std::map <std::string, std::string>&, const std::string&, const std::string&);

bool taskd_is_org      (const Directory&, const std::string&);
bool taskd_is_user     (const Directory&root, const std::string&, const std::string&);
bool taskd_is_user_key (const Directory&root, const std::string&, const std::string&);

std::string taskd_error (const int);

void taskd_staticInitialize ();

// list template
////////////////////////////////////////////////////////////////////////////////
template <class T> void listIntersect (const T& left, const T& right, T& join)
{
  join.clear ();

  for (auto& l : left)
    for (auto& r : right)
      if (l == r)
      {
        join.push_back (l);
        break;
      }
}

#endif
////////////////////////////////////////////////////////////////////////////////
