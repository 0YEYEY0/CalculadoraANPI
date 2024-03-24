#include <iostream>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include "funtras.h"

int main() {
    /**
    // Prueba de divit_t
    boost::multiprecision::cpp_dec_float_50 a_divit_t = -2.2;
    try {
        boost::multiprecision::cpp_dec_float_50 result_divit_t = divi_t(a_divit_t);

        // Imprime el resultado de divit_t
        std::cout << "El resultado de divit_t(" << a_divit_t << ") es: " << result_divit_t << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error en divit_t: " << e.what() << std::endl;
    }

    // Prueba de aproximar_seno
    boost::multiprecision::cpp_dec_float_50 a_sint_t = 80; // Ángulo en radianes

    boost::multiprecision::cpp_dec_float_50 result_aproximar_seno = sin_t(a_sint_t);

    // Imprime el resultado de aproximar_seno
    std::cout << "El resultado de aproximar_seno(" << a_sint_t << ") es: " << result_aproximar_seno << std::endl;

    // Prueba de cos_t
    boost::multiprecision::cpp_dec_float_50 a_cos_t = 80; // Ángulo en radianes
    boost::multiprecision::cpp_dec_float_50 result_cos_t = cos_t(a_cos_t);
    // Imprime el resultado de cos_t
    std::cout << "El resultado de cos_t(" << a_cos_t << ") es: " << result_cos_t << std::endl;


    // Ángulo en radianes
    boost::multiprecision::cpp_dec_float_50 angle = 80; //

    // Prueba de la función tan_t
    boost::multiprecision::cpp_dec_float_50 tan_result = tan_t(angle);

    // Imprimir el resultado de tan_t
    std::cout << "El resultado de tan_t(" << angle << ") radianes es: " << tan_result << std::endl;

    // Ángulo en radianes
    decimal_50_digits angl = 80;

    // Prueba de la función sec_t
    decimal_50_digits sec_result = sec_t(angl);

    // Imprimir el resultado de sec_t
    std::cout << "El resultado de sec_t(" << angl << ") radianes es: " << sec_result << std::endl;

    // Ángulo en radianes
    boost::multiprecision::cpp_dec_float_50 ang = 80; // Supongamos que queremos calcular csc(80)

    // Prueba de la función csc_t
    boost::multiprecision::cpp_dec_float_50 csc_result = csc_t(ang);

    // Imprimir el resultado de csc_t
    std::cout << "El resultado de csc_t(" << ang << ") radianes es: " << csc_result << std::endl;

    // Ángulo en radianes
    boost::multiprecision::cpp_dec_float_50 ange = 45; // Supongamos que queremos calcular cot(45)

    // Prueba de la función cot_t
    boost::multiprecision::cpp_dec_float_50 cot_result = cot_t(ange);

    // Imprimir el resultado de cot_t
    std::cout << "El resultado de cot_t(" << ange << ") radianes es: " << cot_result << std::endl;

    // Definir el valor de x para calcular el logaritmo natural
    boost::multiprecision::cpp_dec_float_50 x = 5; // Puedes cambiar el valor de x según lo necesites

    // Calcular el logaritmo natural de x usando ln_t
    boost::multiprecision::cpp_dec_float_50 ln_result = ln_t(x);

    // Imprimir el resultado
    std::cout << "El logaritmo natural de " << x << " es: " << ln_result << std::endl;


    // Definir los valores de entrada
    decimal_50_digits x_1 = 100; // Valor de x
    decimal_50_digits y_1 = 10; // Valor de y (base del logaritmo)

    // Calcular el logaritmo en base y de x
    decimal_50_digits log_result = log_t(x_1, y_1);

    // Imprimir el resultado
    std::cout << "El logaritmo en base " << y_1 << " de " << x_1 << " es: " << log_result << std::endl;


    // Valor de entrada 'a' para la función sinh_t
    boost::multiprecision::cpp_dec_float_50 a_1 = 1.5; // Por ejemplo, puedes usar 1.5

    // Calcular la aproximación de sinh(a)
    boost::multiprecision::cpp_dec_float_50 sinh_approx = sinh_t(a_1);

    // Imprimir el resultado
    std::cout << "La aproximación de sinh(" << a_1 << ") es: " << sinh_approx << std::endl;


    // Definir el valor de x para el que queremos calcular el coseno hiperbólico
    boost::multiprecision::cpp_dec_float_50 g = 1.5; // Por ejemplo, calcularemos cosh(2)

    // Calcular el coseno hiperbólico de x utilizando nuestra función
    boost::multiprecision::cpp_dec_float_50 cosh_result = cosh_t(g);

    // Imprimir el resultado
    std::cout << "El coseno hiperbólico de " << g << " es: " << cosh_result << std::endl;

    // Definir un valor para x
    decimal_50_digits o = 1.5;

    // Calcular tanh(x)
    decimal_50_digits tanh_x = tanh_t(o);

    // Imprimir el resultado
    std::cout << "La tangente hiperbólica de " << o << " es: " << tanh_x << std::endl;

    // Definir un valor para x
    decimal_50_digits t = 0.5;

    // Calcular atan(x)
    decimal_50_digits atan_x = atan_t(t);

    // Imprimir el resultado
    std::cout << "La tangente inversa  de " << t << " es: " << atan_x << std::endl;

    // Definir el número del que se quiere calcular la raíz y el índice de la raíz
    decimal_50_digits number = 125.0; // Número del que se calculará la raíz
    decimal_50_digits index = 3; // Índice de la raíz

    // Calcular la raíz utilizando la función root_t
    decimal_50_digits root_result = root_t(number, index);

    // Imprimir el resultado
    std::cout << "La raíz " << index << "-ésima de " << number << " es: " << root_result << std::endl;

    // Valor de entrada y parámetros de tolerancia e iteraciones máximas
    decimal_50_digits x_e = 2.0;

    // Calcular la exponencial de x
    decimal_50_digits result = exp_t(x_e);

    // Imprimir el resultado
    std::cout << "exp_t(" << x_e << ") = " << result << std::endl;

    // Valor de entrada
    decimal_50_digits x_p = 2.0;
    int y_p = 3;

    // Calcular x^y
    decimal_50_digits result1 = power_t(x_p, y_p);

    // Imprimir el resultado
    std::cout << x_p << "^" << y_p << " = " << result1 << std::endl;

    // Definir el número para calcular su raíz cuadrada
    decimal_50_digits x_s = 10.0;

    // Calcular la raíz cuadrada de x
    decimal_50_digits sqrt_result = sqrt_t(x_s);

    // Imprimir el resultado

    std::cout << "La raíz cuadrada de " << x_s << " es: " << sqrt_result << std::endl;

    // Definir el valor de x
    decimal_50_digits x_t=0.5;

    // Calcular asin(x)
    decimal_50_digits asin_result = asin_t(x_t);

    // Imprimir el resultado
    std::cout << "asin(" << x_t << ") = " << asin_result << std::endl;

    // Calcular acos(x)
    decimal_50_digits acos_result = acos_t(x_t);

    // Imprimir el resultado

    std::cout << "acos(" << x_t << ") = " << acos_result << std::endl;

    **/
    decimal_50_digits mat;
    //mat = (atan_t(exp_t(-1)));
    //mat = sinh_t(sqrt_t(2));
    mat = root_t((cos_t(3 * divi_t(7))) + ln_t(2), 3) * divi_t(sinh_t(sqrt_t(2))) + (atan_t(exp_t(-1)));
    std::cout << "+++++Fórmula: " << mat << std::endl;
    return 0;
}