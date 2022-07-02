/* This file is part of the the dci project. Copyright (C) 2013-2022 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#include <dci/test.hpp>
#include <dci/test/entryPoint.hpp>

namespace dci::test
{
    API_DCI_TEST int entryPoint(const std::vector<std::string>& argv)
    {
        int c_argc = static_cast<int>(argv.size());
        std::vector<char*> c_argv;
        c_argv.reserve(argv.size());

        std::vector<std::string> argvCopy(argv);

        for(std::string& arg : argvCopy)
        {
            c_argv.push_back(arg.data());
        }
        c_argv.push_back(nullptr);

        testing::InitGoogleTest(&c_argc, c_argv.data());
        int res = RUN_ALL_TESTS();

        return res;
    }
}
