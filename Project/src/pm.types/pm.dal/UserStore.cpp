#include "pch.h"
#include "UserStore.h"

void pm::dal::UserStore::create(pm::type::User user)
{
}

std::vector<pm::type::User> pm::dal::UserStore::getAll()
{
    return std::vector<pm::type::User>();
}

void pm::dal::UserStore::remove(size_t id)
{
}

void pm::dal::UserStore::update(pm::type::User user)
{
}

pm::type::User pm::dal::UserStore::getById(size_t id)
{
    return pm::type::User();
}

pm::type::User pm::dal::UserStore::getByEmail(std::string email)
{
    return pm::type::User();
}

pm::type::User pm::dal::UserStore::getByAge(unsigned short age)
{
    return pm::type::User();
}
