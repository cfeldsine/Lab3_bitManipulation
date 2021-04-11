# Array of tests to run (in order)
# Each test contains
#   description - 
#   steps - A list of steps to perform, each step can have
#       inputs - A list of tuples for the inputs to apply at that step
#       *time - The time (in ms) to wait before continuing to the next step 
#           and before checking expected values for this step. The time should be a multiple of
#           the period of the system
#       *iterations - The number of clock ticks to wait (periods)
#       expected - The expected value at the end of this step (after the "time" has elapsed.) 
#           If this value is incorrect the test will fail early before completing.
#       * only one of these should be used
#   expected - The expected output (as a list of tuples) at the end of this test
# An example set of tests is shown below. It is important to note that these tests are not "unit tests" in 
# that they are not ran in isolation but in the order shown and the state of the device is not reset or 
# altered in between executions (unless preconditions are used).
tests = [ {'description': 'PINA: 0x00 => PINB: 0x00, PINC: 0x00',
    'steps': [ {'inputs': [('PINA',0x00)], 'iterations': 5 } ],
    'expected': [('PORTB',0x00),('PORTC',0x00)],
    },

    {'description': 'PINA: 0xFF => PINB: 0x0F, PINC: 0xF0',
    'steps': [ {'inputs': [('PINA',0xFF)], 'iterations': 5 } ],
    'expected': [('PORTB',0x0F),('PORTC',0xF0)],
    },

    {'description': 'PINA: 0x56 => PINB: 0x05, PINC: 0x60',
    'steps': [ {'inputs': [('PINA',0x56)], 'iterations': 5 } ],
    'expected': [('PORTB',0x05),('PORTC',0x60)],
    },

    {'description': 'PINA: 0xA3 => PINB: 0x0A, PINC: 0x30',
    'steps': [ {'inputs': [('PINA',0xA3)], 'iterations': 5 } ],
    'expected': [('PORTB',0x0A),('PORTC',0x30)],
    },

    {'description': 'PINA: 0x4D => PINB: 0x04, PINC: 0xD0',
    'steps': [ {'inputs': [('PINA',0x4D)], 'iterations': 5 } ],
    'expected': [('PORTB',0x04),('PORTC',0xD0)],
    },

    {'description': 'PINA: 0x91 => PINB: 0x09, PINC: 0x10',
    'steps': [ {'inputs': [('PINA',0x91)], 'iterations': 5 } ],
    'expected': [('PORTB',0x09),('PORTC',0x10)],
    },
]

# Optionally you can add a set of "watch" variables these need to be global or static and may need
# to be scoped at the function level (for static variables) if there are naming conflicts. The 
# variables listed here will display everytime you hit (and stop at) a breakpoint
#watch = ['ignition', 'driver', 'seatbelt']

