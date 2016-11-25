#pragma once

#include <string>
#include <memory>

namespace influxdb {
    namespace api {
        class line;
    }

    namespace async_api {

        class simple_db {
            struct impl;
            std::unique_ptr<impl> pimpl;

        public:
            simple_db(std::string const& url, std::string const& name);
            ~simple_db();

        public:
            void create();
            void drop();
            void insert(influxdb::api::line const& lines);
        };
    }

}
