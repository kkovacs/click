#ifndef POKEHANDLERS_HH
#define POKEHANDLERS_HH
#include "element.hh"
#include "timer.hh"

/*
 * =c
 * PokeHandlers([TIME or HANDLER] ...)
 * =io
 * None
 * =d
 * Runs write handlers automatically at specified times. Each configuration
 * argument should be either `DELAY', a delay in seconds, or
 * `ELEMENT.HANDLERNAME VALUE', a directive to write VALUE into ELEMENT's
 * HANDLERNAME write handler. PokeHandlers processes its arguments in order,
 * writing to handlers as they appear.
 * A `DELAY' directive causes it to wait for DELAY seconds before
 * continuing.
 * =e
 * = PokeHandlers(red.max_p 0.8,
 * =              1.5, // delay for 1.5 seconds
 * =              red.max_p 0.5);
 */

class PokeHandlers : public Element {

  int _pos;
  Vector<Element *> _h_element;
  Vector<String> _h_handler;
  Vector<String> _h_value;
  Vector<int> _h_timeout;
  Timer _timer;

  static void timer_hook(unsigned long);
  
 public:

  PokeHandlers();
  ~PokeHandlers();

  const char *class_name() const		{ return "PokeHandlers"; }
  PokeHandlers *clone() const			{ return new PokeHandlers; }
  int configure(const String &, ErrorHandler *);
  int initialize(ErrorHandler *);
  void uninitialize();

};

#endif
