#include "at32f403a_407_board.h"
#include "at32f403a_407_clock.h"

#define BLINK_DELAY 250

void gpio_config(void)
{
  gpio_init_type gpio_init_struct;

  /* enable the gpioa clock */
  crm_periph_clock_enable(CRM_GPIOC_PERIPH_CLOCK, TRUE);

  /* set default parameter */
  gpio_default_para_init(&gpio_init_struct);

  /* configure the gpio */
  gpio_init_struct.gpio_drive_strength = GPIO_DRIVE_STRENGTH_STRONGER;
  gpio_init_struct.gpio_out_type  = GPIO_OUTPUT_PUSH_PULL;
  gpio_init_struct.gpio_mode = GPIO_MODE_OUTPUT;
  gpio_init_struct.gpio_pins = GPIO_PINS_13;
  gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
  gpio_init(GPIOC, &gpio_init_struct);
}

int main(void)
{
  system_clock_config();

  delay_init();

  gpio_config();

  while(1)
  {

    for(int i=0;i<3;i++) {

      GPIOC->clr = GPIO_PINS_13;
      delay_ms(BLINK_DELAY);
      GPIOC->scr = GPIO_PINS_13;
      delay_ms(BLINK_DELAY);
    }

    delay_ms(BLINK_DELAY*2);

   for(int i=0;i<3;i++) {

      GPIOC->clr = GPIO_PINS_13;
      delay_ms(BLINK_DELAY);
      GPIOC->scr = GPIO_PINS_13;
      delay_ms(BLINK_DELAY);
    }

    delay_ms(BLINK_DELAY*2);

       for(int i=0;i<7;i++) {

      GPIOC->clr = GPIO_PINS_13;
      delay_ms(BLINK_DELAY);
      GPIOC->scr = GPIO_PINS_13;
      delay_ms(BLINK_DELAY);
    }

    delay_ms(BLINK_DELAY*2);

  }
}
