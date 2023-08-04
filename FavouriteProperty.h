#ifndef FAVOURITE_PROPERTY_H
#define FAVOURITE_PROPERTY_H

#include <string>
#include "Property.h"

class FavouriteProperty {
    private:
        Property property;
        string tenantEmail;

    public:
        FavouriteProperty() {}

        FavouriteProperty(const Property &property, const string &tenant) 
        {
            this->property = property;
            this->tenantEmail = tenant;
        }

        Property getProperty() const
        {
            return this->property;
        }

        string getTenantEmail() const
        {
            return this->tenantEmail;
        }
};        

#endif