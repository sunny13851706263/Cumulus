/* 
	Copyright 2010 OpenRTMFP
 
	This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License received along this program for more
	details (or else see http://www.gnu.org/licenses/).

	This file is a part of Cumulus.
*/

#pragma once

#include "Cumulus.h"
#include "Peer.h"
#include "Peers.h"


namespace Cumulus {


class Group : public Entity {
	friend class Peer;
public:
	Group(const Poco::UInt8* id);
	virtual ~Group();

	bool hasPeer(const Poco::UInt8* peerId);
	void addPeer(Peer& peer);
	void removePeer(Peer& peer);
	void bestPeers(std::list<const Peer*>& peers,const Peer& askerPeer);
	bool empty();

private:
	Peers						_peers;
};

inline bool Group::hasPeer(const Poco::UInt8* peerId) {
	return _peers.has(peerId);
}

inline bool Group::empty() {
	return _peers.empty();
}

inline void Group::bestPeers(std::list<const Peer*>& peers,const Peer& askerPeer) {
	_peers.best(peers,askerPeer);
}

} // namespace Cumulus
