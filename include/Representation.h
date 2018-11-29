#pragma once

#define REPTEMPLATE \
template<typename Raw, typename Parsed>

#define REP \
Representation<Raw, Parsed>

REPTEMPLATE
class Representation {
public:
    Representation(Raw&&);
    ~Representation();

    void log_raw() const;
    void log_parsed() const;
    auto get_raw_data();
    auto get_parsed_data() const;


private:
    Raw raw_data;
    const Parsed parsed_data;
};

REPTEMPLATE
REP::Representation(Raw&& _data)
    : raw_data(_data)
    , parsed_data(_data)
{}

REPTEMPLATE
REP::~Representation()
{}

REPTEMPLATE
void REP::log_raw() const
{
    raw_data.log();
}

REPTEMPLATE
void REP::log_parsed() const
{
    parsed_data.log();
}

REPTEMPLATE
auto REP::get_raw_data()
{
    return raw_data.get_data();
}

REPTEMPLATE
auto REP::get_parsed_data() const
{
    return parsed_data.get_data();
}


#undef REPTEMPLATE
#undef REP