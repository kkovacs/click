#ifndef DROPBROADCASTS_HH
#define DROPBROADCASTS_HH
#include "element.hh"

/*
 * =c
 * DropBroadcasts()
 * =d
 * Drop packets that arrived as link-level broadcast or multicast.
 * Used to implement the requirement that IP routers not forward
 * link-level broadcasts.
 * Looks at the mac_broadcast annotation, which FromDevice sets.
 * =a FromDevice
 */

class DropBroadcasts : public Element {
 public:
  
  DropBroadcasts();
  ~DropBroadcasts();
  
  const char *class_name() const		{ return "DropBroadcasts"; }
  Processing default_processing() const	{ return AGNOSTIC; }
  DropBroadcasts *clone() const;
  void add_handlers();

  int drops() const { return(_drops); }

  Packet *simple_action(Packet *);
  /* inline Packet *smaction(Packet *);
     void push(int, Packet *p);
     Packet *pull(int); */

private:
  int _drops;
};

#endif
