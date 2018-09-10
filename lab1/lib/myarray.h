#ifndef MYARRAY_H
#define MYARRAY_H

#include <stdlib.h>
#include <cstring>

namespace  mylib {

    template <class T>
    class array
    {
    private:
        int m_delta, m_size, m_allocated_size;
        T* m_data;
    public:

        array()
        {
            m_allocated_size = m_delta = 1000;
            m_data = new T[m_allocated_size];
            m_size = 0;
        }

        array(int size)
        {
            m_allocated_size = m_delta = size;
            m_data = new T[m_allocated_size];
            m_size = 0;
        }

        bool empty(){
            return m_size;
        }

        void realloc(int size){
            T* dat = new T[size];
            memcpy(dat, m_data, sizeof(T*) * m_size);
            delete[] m_data;
            m_data = dat;
        }

        void push_back(T item)
        {
            if ( m_size == m_allocated_size) {
                m_allocated_size += m_delta;
                realloc(m_allocated_size);
            }
            m_data[m_size++] = item;
        }

        void remove(int index) {
            if (index > 0 || index < m_size) {
                for (int i = index; i < m_size - 1; i++) {
                    m_data[i] = m_data[i + 1];
                }
                m_size--;
            }
        }

        int size(){
            return m_size;
        }

        T at(int index)
        {
            return m_data[index];
        }

        T& operator[](int index) {
               return at(index);
        }


        void qsort(int p, int r,  int comp(T, T))
        {
            if (p < r) {
                int q = partition(p, r, comp);

                qsort(p, q - 1, comp);
                qsort(q + 1, r, comp);
            }
        }

        void qsort(int p, int r)
        {
            if (p < r) {
                int q = partition(p, r);

                qsort(p, q - 1);
                qsort(q + 1, r);
            }
        }

  private:

        int partition(int p, int r, int comp(T, T))
        {
            T x = m_data[p];
            int k = p;
            int l = r + 1;
            T t;
            do k++; while ( ( comp(m_data[k], x) <= 0)  && (k < r));
            do l--; while ( comp( m_data[l], x) > 0 );

            while (k < l) {
                t = m_data[k]; m_data[k] = m_data[l]; m_data[l] = t;
                do k++; while ( comp(m_data[k], x) <= 0 );
                do l--; while ( comp(m_data[l], x) > 0);
            }
            t = m_data[p]; m_data[p] = m_data[l]; m_data[l] = t;
            return l;
        }


        int partition(int p, int r)
        {
            T x = m_data[p];
            int k = p;
            int l = r + 1;
            T t;
            do k++; while (m_data[k] <= x  && k < r);
            do l--; while ( m_data[l] > x );

            while (k < l) {
                t = m_data[k]; m_data[k] = m_data[l]; m_data[l] = t;
                do k++; while ( m_data[k] <=  x );
                do l--; while ( m_data[l] >  x);
            }
            t = m_data[p]; m_data[p] = m_data[l]; m_data[l] = t;
            return l;
        }

    };
}

#endif // MYARRAY_H
