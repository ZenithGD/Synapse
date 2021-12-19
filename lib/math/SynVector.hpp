#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <numeric>

namespace synmath {

    // TODO: Implement iterator and const_iterator
    class SynVector {
    private:
        /**
         * @brief The internal representation of a math vector.
         */
        std::vector<double> _v;

    public:
        /**
         * @brief Construct a new Vector object
         * 
         * @param l The list which initializes the vector object.
         */
        SynVector(std::vector<double> l) : _v(l) {};

        /**
         * @brief Performs vectorwise sum between v (this) and w.
         * In matrix form, it returns \f[
         *      v + w
         * \f]
         * @param w The other vector
         * @return Vector The result of the operation described above
         */
        SynVector operator+(const SynVector& w) {
            std::vector<double> wvec;
            std::transform(_v.begin(), _v.end(), w._v.begin(), wvec.begin(), std::plus<double>());
            return SynVector(wvec);
        }

        /**
         * @brief Performs scalar product between v (this) and w.
         * In matrix form, it returns \f[
         *      v^T \cdot w
         * \f]
         * @param w The other vector
         * @return double The result of the operation described above
         */
        inline double operator*(const SynVector& w) {
            return std::inner_product(_v.begin(), _v.end(), w._v.begin(), 0);
        }

        inline size_t size() const {
            return _v.size();
        }

        friend std::ostream& operator<<(std::ostream& os, const SynVector& v);
    };

    std::ostream& operator<<(std::ostream& os, const SynVector& v) {
        auto s = v._v.size();
        os << "[";
        for ( int i = 0; i < s; i++ ) {
            os << v._v[i];
            if ( i < s - 1 ) { 
                os << ", ";
            }
        }
        os << "]";
        return os;
    }
};

#endif // __VECTOR_H__