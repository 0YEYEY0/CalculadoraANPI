#ifndef FUNTRAS_H
#define FUNTRAS_H

#include <boost/multiprecision/cpp_dec_float.hpp>
typedef boost::multiprecision::cpp_dec_float_50 decimal_50_digits;
#include <regex>
#include <iostream>
#include <cmath>
using namespace std;
// Declaración global de la tolerancia
decimal_50_digits tol = 1.0e-8;
const decimal_50_digits pi_t = 3.1415926535897932384626433832795028841971693993751;

const decimal_50_digits max_iterations = 2500;

decimal_50_digits corregir_num(decimal_50_digits a);
decimal_50_digits sint_t(decimal_50_digits a);
bool multiplo_pi(const decimal_50_digits& x);
decimal_50_digits tan_t(decimal_50_digits a);
decimal_50_digits cos_t(decimal_50_digits x);



decimal_50_digits factorial(decimal_50_digits n) {
    if (n == 0)
        return 1;
    decimal_50_digits result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}


/// <summary>
/// Calcula la aproximación de la inversa de la función trigonométrica t(x) = 2 - a * x, utilizando el método de iteración de punto fijo.
/// El método continúa iterando hasta que se alcanza un valor de convergencia o se supera el número máximo de iteraciones.
/// Si el valor de entrada a es cero, se lanza una advertencia y se devuelve un valor predeterminado de cero.
/// </summary>
/// <param name="a">El valor de entrada para calcular la inversa de la función t(x).</param>
/// <returns>La aproximación de la inversa de la función t(x).</returns>

decimal_50_digits divi_t(decimal_50_digits a) {
    const decimal_50_digits eps = 2.2204e-16;

    decimal_50_digits x0;

    // Calcular el valor absoluto de a
    decimal_50_digits a_1 = abs(a);

    if (a_1 == 0) {
        cerr << "No se puede dividir por cero." << endl;
        return 0; // Valor de retorno predeterminado
    }

    if (a_1 > factorial(80) && a_1 < factorial(100))
        x0 = pow(eps, 15);
    else if (a_1 > factorial(60) && a_1 <= factorial(80))
        x0 = pow(eps, 11);
    else if (a_1 > factorial(40) && a_1 <= factorial(60))
        x0 = pow(eps, 8);
    else if (a_1 > factorial(20) && a_1 <= factorial(40))
        x0 = pow(eps, 4);
    else if (a_1 > 0 && a_1 <= factorial(20))
        x0 = pow(eps, 2);

    decimal_50_digits x_prev = x0;
    decimal_50_digits x_current;
    for (int iterations = 0; iterations < max_iterations; ++iterations) {
        x_current = x_prev * (2 - a_1 * x_prev);
        if (iterations > max_iterations) {
            cerr << "Máximo número de iteraciones alcanzado." << endl;
            break;
        }
        if ((x_current - x_prev >= tol * x_current || x_prev - x_current >= tol * x_current)) {
            x_prev = x_current;
        }
        else {
            break;
        }
    }

    // Verificar si 'a' es negativo
    if (a < 0)
        return x_current * -1; // Si 'a' es negativo, retornar el resultado negativo
    else
        return x_current; // Si 'a' es positivo o cero, retornar el resultado
}

//-------------------------------------------------------------------------------------------------
decimal_50_digits sin_t(decimal_50_digits x)
{
    x = corregir_num(x);
    decimal_50_digits sum = 0;
    decimal_50_digits term = 0;
    decimal_50_digits prev_sum = 0;
    decimal_50_digits prev_term = 0;

    for (int i = 0; i < max_iterations; ++i)
    {
        term = pow(-1, i) * pow(x, 2 * i + 1) * divi_t(factorial(2 * i + 1));
        sum += term;

        if (abs(sum - prev_sum) < tol)
            break;

        prev_sum = sum;
        prev_term = term;
    }

    return sum;
}



decimal_50_digits cos_t(decimal_50_digits x) {
    x = corregir_num(x);
    decimal_50_digits result = 1.0;
    decimal_50_digits currentTerm = 1.0;
    int n = 1;
    while (abs(currentTerm) > tol && n < max_iterations) {
        currentTerm *= -x * x * divi_t(((2 * n - 1) * (2 * n)));
        result += currentTerm;
        n++;
    }
    return result;
}

decimal_50_digits tan_t(decimal_50_digits a)
{
    // Corregir el valor de entrada 'a'
    a = corregir_num(a);

    // Verificar si 'a' es un múltiplo de pi/2
    if (multiplo_pi(a))
    {
        cout << "Error: El valor de a no puede ser un múltiplo de pi/2." << endl;
        return 0;
    }

    // Verificar si el coseno de 'a' es cero
    if (cos_t(a) == 0)
    {
        cout << "Error: La tangente de 'a' es indefinida porque el coseno de 'a' es cero." << endl;
        return 0; // o manejar este caso de manera adecuada, dependiendo de los requisitos del problema
    }

    // Calcular la tangente de 'a'
    decimal_50_digits s = sin_t(a);
    decimal_50_digits c = cos_t(a);
    decimal_50_digits c_1 = divi_t(c);
    return  s * c_1;
}


decimal_50_digits sec_t(decimal_50_digits a) {
    // Corregir el valor de entrada 'a'
    a = corregir_num(a);

    // Verificar si el coseno de 'a' es cero
    if (cos_t(a) == 0) {
        cout << "Error: La función secante no está definida en este punto debido a que el coseno es cero." << endl;
        return 0; // Retorna un valor predeterminado
    }

    // Calcular la secante de 'a'
    return 1 * divi_t(cos_t(a)); // Calcula 1/cos(a) utilizando divi_t
}

decimal_50_digits csc_t(decimal_50_digits a) {
    // Corregir el valor de entrada 'a'
    a = corregir_num(a);

    // Verificar si el seno de 'a' es cero
    if (sin_t(a) == 0) {
        cout << "Error: La función cosecante no está definida en este punto debido a que el seno es cero." << endl;
        return 0; // Retorna un valor predeterminado
    }

    // Calcular la cosecante de 'a'
    return 1 * divi_t(sin_t(a)); // Calcula 1/sin(a) utilizando divi_t
}

decimal_50_digits cot_t(decimal_50_digits x) {
    // Corregir el valor de entrada 'x'
    x = corregir_num(x);

    // Verificar si 'x' es un múltiplo de pi/2
    if (multiplo_pi(x)) {
        cout << "Error: El valor de 'x' no puede ser un múltiplo de pi/2." << endl;
        return 0; // o manejar este caso de manera adecuada, dependiendo de los requisitos del problema
    }

    // Verificar si el coseno de 'x' es cero
    if (cos_t(x) == 0) {
        cout << "Error: La cotangente de 'x' es indefinida porque el coseno de 'x' es cero." << endl;
        return 0; // o manejar este caso de manera adecuada, dependiendo de los requisitos del problema
    }

    // Calcular la cotangente de 'x'
    return divi_t(1 / tan_t(x)); // Calcula 1/tan(x) utilizando la función tan_t
}


decimal_50_digits ln_t(decimal_50_digits x) {
    // Verificar si x es menor o igual a 0
    if (x <= 0) {
        std::cerr << "ln_t: Error - El argumento debe ser mayor que 0." << std::endl;
        return 0; // Retornar un valor predeterminado en caso de error
    }

    decimal_50_digits a = (x - 1) * divi_t((x + 1)); // Calcular 'a' según la fórmula
    decimal_50_digits result = 0; // Inicializar el resultado de la serie
    decimal_50_digits lastResult = 0; // Almacenar el resultado anterior

    for (int n = 0; n < max_iterations; ++n) {
        lastResult = result; // Almacenar el resultado anterior
        decimal_50_digits term = (1.0 * divi_t((2 * n + 1))) * pow(a, 2 * n); // Calcular el término de la serie
        result += term; // Agregar el término al resultado

        // Verificar si se alcanzó la tolerancia
        if (abs(result - lastResult) < tol) {
            break;
        }
    }

    // Multiplicar por 2 * ((x - 1) / (x + 1)) para obtener el resultado de ln(x)
    return 2 * ((x - 1) * divi_t((x + 1))) * result;
}


decimal_50_digits log_t(decimal_50_digits x, decimal_50_digits y) {
    // Verificar si x es menor o igual a 0 o si la base y es menor o igual a 0
    if (x <= 0 || y <= 0) {
        std::cerr << "log_t: Error - El argumento y la base deben ser mayores que 0." << std::endl;
        return 0; // Retornar un valor predeterminado en caso de error
    }

    // Calcular el logaritmo natural de x
    decimal_50_digits ln_x = ln_t(x);

    // Calcular el logaritmo natural de la base y
    decimal_50_digits ln_y = ln_t(y);

    // Verificar si el logaritmo natural de la base es 0, lo que haría indefinido el logaritmo en base y
    if (ln_y == 0) {
        std::cerr << "log_t: Error - La base especificada produce un logaritmo indefinido." << std::endl;
        return 0; // Retornar un valor predeterminado en caso de error
    }

    // Calcular el logaritmo en base y usando la fórmula: log_y(x) = ln(x) / ln(y)
    return ln_x * divi_t(ln_y);
}

decimal_50_digits sinh_t(decimal_50_digits a) {
    decimal_50_digits result;
    decimal_50_digits term;

    for (int n = 0; n < max_iterations; ++n) {
        decimal_50_digits lastResult = result;
        result = term;
        term += pow(a, (2 * n + 1)) * divi_t(factorial(2 * n + 1));

        // Verificar si se alcanzó la tolerancia
        if (abs(term - result) < tol) {
            break;
        }
    }

    return result;
}

decimal_50_digits cosh_t(decimal_50_digits x) {
    decimal_50_digits result = 1.0;
    decimal_50_digits currentTerm = 1.0;
    int n = 1;

    while (abs(currentTerm) > tol && n < max_iterations) {
        currentTerm = pow(x, 2 * n) * divi_t(factorial(2 * n));
        result += currentTerm;
        n++;
    }

    return result;
}

decimal_50_digits tanh_t(decimal_50_digits x) {
    // Calcular el coseno hiperbólico de x
    decimal_50_digits cosh_x = cosh_t(x);

    // Verificar si cosh_x es cero
    if (cosh_x == 0) {
        std::cerr << "tanh_t: Error - La función no está definida para este valor de x." << std::endl;
        return 0; // Retornar un valor predeterminado en caso de error
    }

    // Calcular el seno hiperbólico de x
    decimal_50_digits sinh_x = sinh_t(x);

    // Calcular la tangente hiperbólica de x
    return sinh_x * divi_t(cosh_x);
}


decimal_50_digits atan_t(decimal_50_digits x) {
    decimal_50_digits result = 0.0;
    decimal_50_digits term;
    int n = 0;

    if (-1 <= x && x <= 1) {
        while (true) {
            decimal_50_digits lastResult = result;
            term = pow(-1, n) * divi_t(2 * n + 1) * pow(x, 2 * n + 1);
            result += term;

            if (abs(term) < tol) {
                break;
            }

            n++;
        }
    }
    else if (x > 1) {
        result = pi_t * divi_t(2);
        x = 1 * divi_t(x);

        while (true) {
            decimal_50_digits lastResult = result;
            term = pow(-1, n) * divi_t(2 * n + 1) * pow(x, 2 * n + 1);
            result -= term;

            if (abs(term) < tol) {
                break;
            }

            n++;
        }
    }
    else {
        result = -pi_t / 2;
        x = 1 * divi_t(x);

        while (true) {
            decimal_50_digits lastResult = result;
            term = pow(-1, n) * divi_t(2 * n + 1) * pow(x, 2 * n + 1);
            result -= term;

            if (abs(term) < tol) {
                break;
            }

            n++;
        }
    }

    return result;
}

decimal_50_digits root_t(const decimal_50_digits x, const decimal_50_digits  y) {
    decimal_50_digits resul = x * divi_t(2);
    decimal_50_digits temr;

    if (y > decimal_50_digits("2") &&
        y == floor(x) &&
        x > 0) {
        int int_num = static_cast<int>(y);
        if (int_num % 2 == 0)
        {
            for (int n = 1; n < max_iterations; n++) {
                temr = resul - ((pow(resul, int_num) - x) *
                    divi_t(int_num * pow(resul, int_num - 1)));

                if (abs(temr - resul) < (tol * (temr)))
                    return temr;

                resul = temr;
            }
        }
    }
    else if (x > 0) {
        return pow(x, 1 * divi_t(y));
    }
    else

        std::cout << "Error: x negativa o y no entera o menor 3." << std::endl;
    return 1;
}



decimal_50_digits corregir_num(decimal_50_digits a)
{
    // Si a es menor que 0, agregamos múltiplos de 2*pi_t hasta que sea no negativo
    while (a < 0) {
        a += 2 * pi_t;
    }

    // Si a es mayor que 2*pi_t, restamos múltiplos de 2*pi_t hasta que esté en el rango [0, 2*pi_t]
    while (a > 2 * pi_t) {
        a -= 2 * pi_t;
    }

    return a;
}


bool multiplo_pi(const decimal_50_digits& x) {
    decimal_50_digits half_pi = pi_t * decimal_50_digits("0.5");
    decimal_50_digits rounded_division = round(x * divi_t(half_pi));
    decimal_50_digits diff = abs(x - rounded_division * half_pi);
    return diff < tol || diff > half_pi - tol;
}



#endif // FUNTRAS_H