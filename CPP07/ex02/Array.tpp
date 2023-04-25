/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hania <hania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 09:27:10 by hania             #+#    #+#             */
/*   Updated: 2023/04/25 10:36:59 by hania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array() 
    : _data( NULL )
    , _size( 0 )
{}

template <typename T>
Array<T>::Array( unsigned int n ) 
    : _data( new T[n] )
    , _size( n )
{}

template <typename T>
Array<T>::Array( const Array<T>& ref ) 
    : _data( new T[ref._size] )
    , _size( ref._size )
{
    for ( size_t i = 0; i < _size; ++i )
        _data[i] = ref._data[i];
}

template <typename T>
Array<T>::~Array() {
    delete[] _data;
}

template <typename T>
Array<T>& Array<T>::operator=( const Array<T>& rhs ) {
    if (this != &rhs)
    {
        T* temp = new T[rhs._size];
        for ( size_t i = 0; i < rhs._size; ++i )
            temp[i] = rhs._data[i];
        delete[] _data;
        _data = temp;
        _size = rhs._size;
    }
    return *this;
}

template<typename T>
const char		*Array<T>::InvalidIndexException::what() const throw() { 
    return "Invalid index"; 
}

template <typename T>
T& Array<T>::operator[]( unsigned int i ) {
    if ( i >= _size )
        throw Array<T>::InvalidIndexException();
    return _data[i];
}

template <typename T>
const T& Array<T>::operator[]( unsigned int i ) const {
    if ( i >= _size )
        throw Array<T>::InvalidIndexException();
    return _data[i];
}

template <typename T>
size_t Array<T>::size() const {
    return _size;
}