#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <vector>
#include <Matrix.hpp>

namespace synmath {

    class Vector : public Matrix {
    public:
        /**
         * @brief Construct a new Vector object
         * 
         * @param l The list which initializes the vector object.
         */
        Vector(std::initializer_list<double> l);

        /**
         * @brief Performs vectorwise sum between v (this) and w.
         * In matrix form, it returns \f[
         *      v + w
         * \f]
         * @param w The other vector
         * @return Vector The result of the operation described above
         */
        Vector operator+(const Vector& w);

        /**
         * @brief Performs scalar product between v (this) and w.
         * In matrix form, it returns \f[
         *      v^T \cdot w
         * \f]
         * @param w The other vector
         * @return Vector The result of the operation described above
         */
        Vector operator*(const Vector& w);

        /**
         * @brief Performs vectorwise sum between v (this) and w.
         * In matrix form, it returns \f[
         *      v - w
         * \f]
         * @param w The other vector
         * @return Vector The result of the operation described above
         */
        Vector operator-(const Vector& w);
    };
};

#endif // __VECTOR_H__