#ifndef __COLLECTION__
#define __COLLECTION__

#include <string>
#include "../misc/misc_package.h"
#include "../datastructs/dataelement.h"

class Collection
{
 public:
    typedef SmartVector<DataElement> element_vector;
       
 protected:
    std::string d_name, d_type, d_dir_name;
    
 public:
    element_vector d_collection;
    
    
 public:
    Collection(std::string name, std::string type, std::string dir_name)
    :
        d_name(name),
        d_type(type),
        d_dir_name(dir_name)
    {
        
    }

    virtual void add(smart_pointer<DataElement> element_pointer)
    {
        d_collection.push_back(element_pointer);
    }

    virtual void load()
    {
        
    }
    
    virtual void save()
    {
        if (!exists())
            create();
        
    }

    virtual bool exists()
    {
        return false;
    }
    
    virtual void create()
    {
        make_dir(d_dir_name);
    }
    
    element_vector &collection()
    {
        return d_collection;
    }
};

#endif
