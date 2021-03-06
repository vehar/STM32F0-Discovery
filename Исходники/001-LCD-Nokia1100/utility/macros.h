/*
 *	File:	macros.h (STM32F0xx)
 *	Date:	31.08.2012
 *	Denis Zheleznyakov http://ziblog.ru
 */

#ifndef MACROS_H_
#define MACROS_H_

#define BIT(NUMBER)            		(1UL << (NUMBER))

#define ARRAY_LENGHT(Value)			(sizeof(Value) / sizeof(Value[0]))

typedef enum {FALSE = 0, TRUE = 1} flags;

typedef signed long  int32_t;
typedef signed short int16_t;
typedef signed char  int8_t;

typedef unsigned long  uint32_t;
typedef unsigned short uint16_t;
typedef unsigned char  uint8_t;

//------------------------------------------------------------------------------
#define MODE_OUTPUT_PUSH_PULL					MODE_OUTPUT_PUSH_PULL
#define MODE_OUTPUT_PUSH_PULL_PULL_UP			MODE_OUTPUT_PUSH_PULL_PULL_UP
#define MODE_OUTPUT_PUSH_PULL_PULL_DOWN			MODE_OUTPUT_PUSH_PULL_PULL_DOWN
#define MODE_OUTPUT_OPEN_DRAIN					MODE_OUTPUT_OPEN_DRAIN
#define MODE_OUTPUT_OPEN_DRAIN_PULL_UP			MODE_OUTPUT_OPEN_DRAIN_PULL_UP
#define MODE_OUTPUT_OPEN_DRAIN_PULL_DOWN		MODE_OUTPUT_OPEN_DRAIN_PULL_DOWN

#define MODE_AF_PUSH_PULL						MODE_AF_PUSH_PULL
#define MODE_AF_PUSH_PULL_PULL_UP				MODE_AF_PUSH_PULL_PULL_UP
#define MODE_AF_PUSH_PULL_PULL_DOWN				MODE_AF_PUSH_PULL_PULL_DOWN
#define MODE_AF_OPEN_DRAIN						MODE_AF_OPEN_DRAIN
#define MODE_AF_OPEN_DRAIN_PULL_UP				MODE_AF_OPEN_DRAIN_PULL_UP
#define MODE_AF_OPEN_DRAIN_PULL_DOWN			MODE_AF_OPEN_DRAIN_PULL_DOWN

#define MODE_INPUT_FLOATING						MODE_INPUT_FLOATING
#define MODE_INPUT_PULL_UP						MODE_INPUT_PULL_UP
#define MODE_INPUT_PULL_DOWN					MODE_INPUT_PULL_DOWN

#define MODE_ANALOG								MODE_ANALOG

#define SPEED_2MHZ								SPEED_2MHZ
#define SPEED_10MHZ								SPEED_10MHZ
#define SPEED_50MHZ								SPEED_50MHZ

#define AF_NO									0UL
#define AF0										0UL
#define AF1										1UL
#define AF2										2UL
#define AF3										3UL
#define AF4										4UL
#define AF5										5UL
#define AF6										6UL
#define AF7										7UL

//------------------------------------------------------------------------------
#define GPIO_PIN_MODE_INPUT(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
		{ GPIO##PORT->MODER &= ~(3UL << (PIN * 2UL)); }
#define GPIO_PIN_MODE_OUTPUT(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
		{ GPIO##PORT->MODER &= ~(3UL << (PIN * 2UL)); \
		  GPIO##PORT->MODER |= (1UL << (PIN * 2UL)); }
#define GPIO_PIN_MODE_ALTERNATE(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
		{ GPIO##PORT->MODER &= ~(3UL << (PIN * 2UL)); \
		  GPIO##PORT->MODER |= (2UL << (PIN * 2UL)); }
#define GPIO_PIN_MODE_ANALOG(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
		{ GPIO##PORT->MODER |= (3UL << (PIN * 2UL)); }

//------------------------------------------------------------------------------
#define GPIO_PIN_SPEED_2MHZ(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
		{ GPIO##PORT->OSPEEDR &= ~(3UL << (PIN * 2UL)); }
#define GPIO_PIN_SPEED_10MHZ(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
		{ GPIO##PORT->OSPEEDR &= ~(3UL << (PIN * 2UL)); \
		  GPIO##PORT->OSPEEDR |= (1UL << (PIN * 2UL)); }
#define GPIO_PIN_SPEED_50MHZ(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
		{ GPIO##PORT->OSPEEDR |= (3UL << (PIN * 2UL)); }

//------------------------------------------------------------------------------
#define GPIO_PIN_PUSH_PULL(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
		{ GPIO##PORT->OTYPER &= ~(1UL << (PIN)); }
#define GPIO_PIN_OPEN_DRAIN(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
		{ GPIO##PORT->OTYPER |= (1UL << (PIN)); }

//------------------------------------------------------------------------------
#define GPIO_PIN_NO_PULL(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
		{ GPIO##PORT->PUPDR &= ~(3UL << (PIN * 2UL)); }
#define GPIO_PIN_PULL_UP(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
		{ GPIO##PORT->PUPDR &= ~(3UL << (PIN * 2UL)); \
		  GPIO##PORT->PUPDR |= (1UL << (PIN * 2UL)); }
#define GPIO_PIN_PULL_DOWN(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
		{ GPIO##PORT->PUPDR &= ~(3UL << (PIN * 2UL)); \
		  GPIO##PORT->PUPDR |= (2UL << (PIN * 2UL)); }

//------------------------------------------------------------------------------
#define GPIO_PIN0_AF(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
			{ GPIO##PORT->AFRL &= ~(15UL << 0); \
			  GPIO##PORT->AFRL |= ((ALTERNATE) << 0); }
#define GPIO_PIN1_AF(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
			{ GPIO##PORT->AFRL &= ~(15UL << 4); \
			  GPIO##PORT->AFRL |= ((ALTERNATE) << 4); }
#define GPIO_PIN2_AF(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
			{ GPIO##PORT->AFRL &= ~(15UL << 8); \
			  GPIO##PORT->AFRL |= ((ALTERNATE) << 8); }
#define GPIO_PIN3_AF(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
			{ GPIO##PORT->AFRL &= ~(15UL << 12); \
			  GPIO##PORT->AFRL |= ((ALTERNATE) << 12); }
#define GPIO_PIN4_AF(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
			{ GPIO##PORT->AFRL &= ~(15UL << 16); \
			  GPIO##PORT->AFRL |= ((ALTERNATE) << 16); }
#define GPIO_PIN5_AF(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
			{ GPIO##PORT->AFRL &= ~(15UL << 20); \
			  GPIO##PORT->AFRL |= ((ALTERNATE) << 20); }
#define GPIO_PIN6_AF(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
			{ GPIO##PORT->AFRL &= ~(15UL << 24); \
			  GPIO##PORT->AFRL |= ((ALTERNATE) << 24); }
#define GPIO_PIN7_AF(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
			{ GPIO##PORT->AFRL &= ~(15UL << 28); \
			  GPIO##PORT->AFRL |= ((ALTERNATE) << 28); }
#define GPIO_PIN8_AF(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
			{ GPIO##PORT->AFRH &= ~(15UL << 0); \
			  GPIO##PORT->AFRH |= ((ALTERNATE) << 0); }
#define GPIO_PIN9_AF(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
			{ GPIO##PORT->AFRH &= ~(15UL << 4); \
			  GPIO##PORT->AFRH |= ((ALTERNATE) << 4); }
#define GPIO_PIN10_AF(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
			{ GPIO##PORT->AFRH &= ~(15UL << 8); \
			  GPIO##PORT->AFRH |= ((ALTERNATE) << 8); }
#define GPIO_PIN11_AF(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
			{ GPIO##PORT->AFRH &= ~(15UL << 12); \
			  GPIO##PORT->AFRH |= ((ALTERNATE) << 12); }
#define GPIO_PIN12_AF(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
			{ GPIO##PORT->AFRH &= ~(15UL << 16); \
			  GPIO##PORT->AFRH |= ((ALTERNATE) << 16); }
#define GPIO_PIN13_AF(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
			{ GPIO##PORT->AFRH &= ~(15UL << 20); \
			  GPIO##PORT->AFRH |= ((ALTERNATE) << 20); }
#define GPIO_PIN14_AF(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
			{ GPIO##PORT->AFRH &= ~(15UL << 24); \
			  GPIO##PORT->AFRH |= ((ALTERNATE) << 24); }
#define GPIO_PIN15_AF(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
			{ GPIO##PORT->AFRH &= ~(15UL << 28); \
			  GPIO##PORT->AFRH |= ((ALTERNATE) << 28); }

//------------------------------------------------------------------------------
#define GPIO_CONFIGURATION_MODE_OUTPUT_PUSH_PULL(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
		{ \
			GPIO_PIN_MODE_OUTPUT(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
			GPIO_PIN_PUSH_PULL(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
			GPIO_PIN_NO_PULL(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
		 	GPIO_PIN_##SPEED(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
		}
#define GPIO_CONFIGURATION_MODE_OUTPUT_PUSH_PULL_PULL_UP(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
		{ \
			GPIO_PIN_MODE_OUTPUT(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
			GPIO_PIN_PUSH_PULL(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
			GPIO_PIN_PULL_UP(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
		 	GPIO_PIN_##SPEED(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
		}
#define GPIO_CONFIGURATION_MODE_OUTPUT_PUSH_PULL_PULL_DOWN(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
		{ \
			GPIO_PIN_MODE_OUTPUT(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
			GPIO_PIN_PUSH_PULL(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
			GPIO_PIN_PULL_DOWN(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
		 	GPIO_PIN_##SPEED(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
		}

//------------------------------------------------------------------------------
#define GPIO_CONFIGURATION_MODE_OUTPUT_OPEN_DRAIN(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
		{ \
			GPIO_PIN_MODE_OUTPUT(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
			GPIO_PIN_OPEN_DRAIN(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
			GPIO_PIN_NO_PULL(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
		 	GPIO_PIN_##SPEED(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
		}
#define GPIO_CONFIGURATION_MODE_OUTPUT_OPEN_DRAIN_PULL_UP(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
		{ \
			GPIO_PIN_MODE_OUTPUT(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
			GPIO_PIN_OPEN_DRAIN(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
			GPIO_PIN_PULL_UP(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
		 	GPIO_PIN_##SPEED(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
		}
#define GPIO_CONFIGURATION_MODE_OUTPUT_OPEN_DRAIN_PULL_DOWN(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
		{ \
			GPIO_PIN_MODE_OUTPUT(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
			GPIO_PIN_OPEN_DRAIN(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
			GPIO_PIN_PULL_DOWN(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
		 	GPIO_PIN_##SPEED(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
		}

//------------------------------------------------------------------------------
#define GPIO_CONFIGURATION_MODE_AF_PUSH_PULL(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
		{ \
			GPIO_PIN_MODE_ALTERNATE(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
			GPIO_PIN_PUSH_PULL(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
			GPIO_PIN_NO_PULL(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
		 	GPIO_PIN_##SPEED(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
		 	GPIO_PIN##PIN##_AF(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
		}
#define GPIO_CONFIGURATION_MODE_AF_PUSH_PULL_PULL_UP(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
		{ \
			GPIO_PIN_MODE_ALTERNATE(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
			GPIO_PIN_PUSH_PULL(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
			GPIO_PIN_PULL_UP(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
		 	GPIO_PIN_##SPEED(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
		 	GPIO_PIN##PIN##_AF(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
		}
#define GPIO_CONFIGURATION_MODE_AF_PUSH_PULL_PULL_DOWN(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
		{ \
			GPIO_PIN_MODE_ALTERNATE(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
			GPIO_PIN_PUSH_PULL(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
			GPIO_PIN_PULL_DOWN(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
		 	GPIO_PIN_##SPEED(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
		 	GPIO_PIN##PIN##_AF(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
		}

//------------------------------------------------------------------------------
#define GPIO_CONFIGURATION_MODE_AF_OPEN_DRAIN(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
		{ \
			GPIO_PIN_MODE_ALTERNATE(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
			GPIO_PIN_OPEN_DRAIN(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
			GPIO_PIN_NO_PULL(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
		 	GPIO_PIN_##SPEED(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
		 	GPIO_PIN##PIN##_AF(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
		}
#define GPIO_CONFIGURATION_MODE_AF_OPEN_DRAIN_PULL_UP(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
		{ \
			GPIO_PIN_MODE_ALTERNATE(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
			GPIO_PIN_OPEN_DRAIN(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
			GPIO_PIN_PULL_UP(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
		 	GPIO_PIN_##SPEED(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
		 	GPIO_PIN##PIN##_AF(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
		}
#define GPIO_CONFIGURATION_MODE_AF_OPEN_DRAIN_PULL_DOWN(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
		{ \
			GPIO_PIN_MODE_ALTERNATE(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
			GPIO_PIN_OPEN_DRAIN(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
			GPIO_PIN_PULL_DOWN(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
		 	GPIO_PIN_##SPEED(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
		 	GPIO_PIN##PIN##_AF(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
		}

//------------------------------------------------------------------------------
#define GPIO_CONFIGURATION_MODE_INPUT_FLOATING(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
		{ \
			GPIO_PIN_MODE_INPUT(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
			GPIO_PIN_NO_PULL(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
		}
#define GPIO_CONFIGURATION_MODE_INPUT_PULL_UP(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
		{ \
			GPIO_PIN_MODE_INPUT(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
			GPIO_PIN_PULL_UP(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
		}
#define GPIO_CONFIGURATION_MODE_INPUT_PULL_DOWN(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
		{ \
			GPIO_PIN_MODE_INPUT(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
			GPIO_PIN_PULL_DOWN(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
		}

//------------------------------------------------------------------------------
#define GPIO_CONFIGURATION_MODE_ANALOG(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
		{ \
			GPIO_PIN_MODE_ANALOG(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
			GPIO_PIN_NO_PULL(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); \
		}

//------------------------------------------------------------------------------
#define GPIO_PIN_CONFIGURATION(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
			{ GPIO_CONFIGURATION_##MODE(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE); }

//------------------------------------------------------------------------------
#define GPIO_PIN_ON_HIGH(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
			{ GPIO##PORT->BSRR = (1UL << PIN); }

#define GPIO_PIN_ON_LOW(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
			{ GPIO##PORT->BRR = (1UL << PIN); }

#define GPIO_PIN_OFF_HIGH(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
			{ GPIO##PORT->BRR = (1UL << PIN); }

#define GPIO_PIN_OFF_LOW(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
			{ GPIO##PORT->BSRR = (1UL << PIN); }

//------------------------------------------------------------------------------
#define GPIO_PIN_ON(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
			{ GPIO_PIN_ON_##LEVEL(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) }

#define GPIO_PIN_OFF(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
			{ GPIO_PIN_OFF_##LEVEL(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) }

//------------------------------------------------------------------------------
#define GPIO_PIN_SIGNAL_HIGH(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
			( (GPIO##PORT->IDR & (1UL << PIN)) == (1UL << PIN) )

#define GPIO_PIN_SIGNAL_LOW(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
		( (GPIO##PORT->IDR & (1UL << PIN)) != (1UL << PIN) )

#define GPIO_PIN_SIGNAL(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
			( GPIO_PIN_SIGNAL_##LEVEL(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) )

//------------------------------------------------------------------------------
#define GPIO_PIN_BITBAND(PORT, PIN, LEVEL, MODE, SPEED, ALTERNATE) \
			(*(volatile  uint32_t *) (PERIPH_BB_BASE + (((GPIO##PORT##_BASE - PERIPH_BASE) + 0x14) * 0x20) + PIN * 4))

//------------------------------------------------------------------------------
#define PIN_CONFIGURATION(PIN_DESCRIPTION) GPIO_PIN_CONFIGURATION(PIN_DESCRIPTION)
#define PIN_IN(PIN_DESCRIPTION) GPIO_PIN_MODE_INPUT(PIN_DESCRIPTION)
#define PIN_OUT(PIN_DESCRIPTION) GPIO_PIN_MODE_OUTPUT(PIN_DESCRIPTION)
#define PIN_ON(PIN_DESCRIPTION) GPIO_PIN_ON(PIN_DESCRIPTION)
#define PIN_OFF(PIN_DESCRIPTION) GPIO_PIN_OFF(PIN_DESCRIPTION)
#define PIN_SIGNAL(PIN_DESCRIPTION) GPIO_PIN_SIGNAL(PIN_DESCRIPTION)
#define PIN_BITBAND(PIN_DESCRIPTION) GPIO_PIN_BITBAND(PIN_DESCRIPTION)

void delay_ms(uint16_t value);

#endif /* MACROS_H_ */
