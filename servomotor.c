#include <stdio.h> // biblioteca padrão da linguagem C
#include "pico/stdlib.h" // subconjunto central de bibliotecas do SDK Pico
#include "hardware/pwm.h" // biblioteca para controlar o hardware de PWM

#define PWM_PIN 22 // pino conectado ao servomotor
#define LED_PIN 12 // pino conectado ao LED RGB (GPIO 12)

int duty_cycle_value  = 500; // valor inicial do ciclo de trabalho em microssegundos (0 graus)

// Configuração do PWM para o servomotor com 50Hz (período de 20ms)
void config_pwm(){
    stdio_init_all(); // inicializa o sistema padrão de I/O

    gpio_set_function(PWM_PIN, GPIO_FUNC_PWM); // habilitar o pino GPIO como PWM
    gpio_set_function(LED_PIN, GPIO_FUNC_PWM); // habilitar o pino GPIO do LED RGB como PWM

    uint slice = pwm_gpio_to_slice_num(PWM_PIN); // obter o canal PWM da GPIO (slice)
    uint slice_rgb = pwm_gpio_to_slice_num(LED_PIN); // obter o canal PWM para o LED RGB

    pwm_set_clkdiv(slice, 125.0); // define o divisor de clock do PWM (ajustado para 50Hz)
    pwm_set_clkdiv(slice_rgb, 125.0); // define o divisor de clock do PWM para o LED RGB

    pwm_set_wrap(slice, 19999); // define o valor de wrap para 50Hz (período de 20ms)
    pwm_set_wrap(slice_rgb, 19999); // valor de wrap para o LED RGB

    pwm_set_gpio_level(PWM_PIN, duty_cycle_value ); // definir o ciclo de trabalho (duty cycle) do PWM dado em microssegundo
    pwm_set_enabled(slice, true); // habilita o PWM no slice correspondente

    pwm_set_enabled(slice_rgb, true); // habilita o PWM no slice correspondente do LED RGB
}

// Movimento primário: ajusta o servo para 180°, 90° e 0° com tempos de espera de 5 segundos
void movimento_primario(){
    pwm_set_gpio_level(PWM_PIN, 2400); // 180 graus
    sleep_ms(5000); // aguarda 5 segundos

    pwm_set_gpio_level(PWM_PIN, 1470); // 90 graus
    sleep_ms(5000); // aguarda 5 segundos

    pwm_set_gpio_level(PWM_PIN, 500); // 0 graus
    sleep_ms(5000); // aguarda 5 segundos
}

// Incrementa o ciclo de trabalho para suavizar o movimento
void incrementa(){
    duty_cycle_value  += 5; 
    pwm_set_gpio_level(PWM_PIN, duty_cycle_value ); // aumenta o ciclo de trabalho (duty cycle) em 5µs
    sleep_ms(10); // atraso de 10ms para suavizar o movimento
}

// Decrementa o ciclo de trabalho para suavizar o movimento
void decrementa(){
    duty_cycle_value  -= 5; 
    pwm_set_gpio_level(PWM_PIN, duty_cycle_value ); // diminui o ciclo de trabalho (duty cycle) em 5µs
    sleep_ms(10); // atraso de 10ms para suavizar o movimento
}

// Movimento secundário: movimentação suave entre 0 e 180 graus
void movimento_secundario(){
    while(duty_cycle_value  < 2400) {
        incrementa();
    }

    sleep_ms(1000); // espera 1 segundo na posição de 180 graus

    while(duty_cycle_value  > 500) {
        decrementa();
    }

    sleep_ms(1000); // espera 1 segundo na posição de 0 graus
}

// Experimento com LED RGB para observar a variação de brilho
void experimento_led_rgb(){
    pwm_set_gpio_level(LED_PIN, 1024);  // LED RGB com brilho de 50% (aproximadamente)
    sleep_ms(1000); // aguarda 1 segundo

    pwm_set_gpio_level(LED_PIN, 512);  // LED RGB com brilho de 25%
    sleep_ms(1000); // aguarda 1 segundo

    pwm_set_gpio_level(LED_PIN, 2048);  // LED RGB com brilho de 100%
    sleep_ms(1000); // aguarda 1 segundo

    pwm_set_gpio_level(LED_PIN, 0);  // LED RGB apagado
    sleep_ms(1000); // aguarda 1 segundo
}

// Função principal
int main()
{
   config_pwm(); // Configura o PWM para o servomotor e LED RGB

   movimento_primario(); // Realiza o movimento primário para 180°, 90° e 0°

   while(1){
      movimento_secundario(); // Realiza a movimentação suave entre 0° e 180°
      experimento_led_rgb(); // Realiza o experimento com o LED RGB
   }

   return 0;
}
