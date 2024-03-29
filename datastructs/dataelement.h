#ifndef __DATA_ELEMENT__
#define __DATA_ELEMENT__

#include <vector>

#include "../misc/misc_package.h"

class DataElement
{
 public:
    typedef std::vector<float> data_vector;
 
    DataElement(data_vector const &d_vec) : data(d_vec)
    {}
    
    DataElement(data_vector const &d_vec, Context const &m_data) : data(d_vec), meta_data(m_data)
    {}
    
 public:   
    data_vector data;
    Context meta_data;

    template <typename T>
    T get_meta(std::string name)
    {
        return string_to_t<T>(meta_data[name]);
    }
    
    template <typename T>
    void set_meta(std::string name, T value)
    {
        meta_data[name] = t_to_string(value);
    }

    void print()
    {
        meta_data.print();
    }
    
    DataElement(){meta_data.print();}
};

#endif
