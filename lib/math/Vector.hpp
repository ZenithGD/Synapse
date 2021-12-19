#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <vector>
#include <Matrix.hpp>

namespace synmath {

    class SynVector : public SynMatrix {
    public:
        /**
         * @brief Construct a new Vector object
         * 
         * @param l The list which initializes the vector object.
         */
        SynVector(std::initializer_list<double> l);

        /**
         * @brief Performs vectorwise sum between v (this) and w.
         * In matrix form, it returns \f[
         *      v + w
         * \f]
         * @param w The other vector
         * @return Vector The result of the operation described above
         */
        SynVector operator+(const SynVector& w);

        /**
         * @brief Performs scalar product between v (this) and w.
         * In matrix form, it returns \f[
         *      v^T \cdot w
         * \f]
         * @param w The other vector
         * @return Vector The result of the operation described above
         */
        SynVector operator*(const SynVector& w);

        /**
         * @brief Performs vectorwise sum between v (this) and w.
         * In matrix form, it returns \f[
         *      v - w
         * \f]
         * @param w The other vector
         * @return Vector The result of the operation described above
         */
        SynVector operator-(const SynVector& w);
    };
};

#endif // __VECTOR_H__