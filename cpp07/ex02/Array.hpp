/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 22:53:21 by abrisse           #+#    #+#             */
/*   Updated: 2023/12/26 23:46:13 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template<typename T>
class Array {

	private:

		T *				_array;
		unsigned int	_size;

	public:

		Array() : _array(NULL), _size(0) { };

		Array(unsigned int n) : _array(new T[n]), _size(n) { };
		
		Array(Array const & src) {
			_size = src._size;
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = src._array[i];
		};

		Array &	operator=(Array const & src) {
			if (this != &src) 
			{
				delete [] _array;
				_size = src._size;
				_array = new T[_size];
				for (unsigned int i = 0; i < _size; i++)
					_array[i] = src._array[i];
			}
			return *this;
		};

		~Array() {
			delete [] _array;
		};

		T &	operator[](unsigned int index) {
			if (index >= _size)
				throw std::exception();
			return _array[index];
		};

		unsigned int	size() const {
			return _size;
		};
};