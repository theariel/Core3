/*
 *	server/zone/ZoneClientSession.cpp generated by engine3 IDL compiler 0.60
 */

#include "ZoneClientSession.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/ZoneServer.h"

/*
 *	ZoneClientSessionStub
 */

enum {RPC_DISCONNECT__ = 6,RPC_DISCONNECT__BOOL_,RPC_SENDMESSAGE__BASEPACKET_,RPC_BALANCEPACKETCHECKUPTIME__,RPC_RESETPACKETCHECKUPTIME__,RPC_CLOSECONNECTION__BOOL_BOOL_,RPC_INFO__STRING_BOOL_,RPC_ERROR__STRING_,RPC_GETADDRESS__,RPC_SETPLAYER__SCENEOBJECT_,RPC_SETSESSIONID__INT_,RPC_SETACCOUNTID__INT_,RPC_GETCOMMANDCOUNT__,RPC_INCREASECOMMANDCOUNT__,RPC_RESETCOMMANDCOUNT__,RPC_GETPLAYER__,RPC_GETSESSIONID__,RPC_GETACCOUNTID__,RPC_HASCHARACTER__LONG_,RPC_ADDCHARACTER__LONG_,RPC_RESETCHARACTERS__};

ZoneClientSession::ZoneClientSession(BaseClientProxy* session) : ManagedObject(DummyConstructorParameter::instance()) {
	ZoneClientSessionImplementation* _implementation = new ZoneClientSessionImplementation(session);
	_impl = _implementation;
	_impl->_setStub(this);
	_setClassName("ZoneClientSession");
}

ZoneClientSession::ZoneClientSession(DummyConstructorParameter* param) : ManagedObject(param) {
	_setClassName("ZoneClientSession");
}

ZoneClientSession::~ZoneClientSession() {
}



void ZoneClientSession::disconnect() {
	ZoneClientSessionImplementation* _implementation = static_cast<ZoneClientSessionImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_DISCONNECT__);

		method.executeWithVoidReturn();
	} else
		_implementation->disconnect();
}

void ZoneClientSession::disconnect(bool doLock) {
	ZoneClientSessionImplementation* _implementation = static_cast<ZoneClientSessionImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_DISCONNECT__BOOL_);
		method.addBooleanParameter(doLock);

		method.executeWithVoidReturn();
	} else
		_implementation->disconnect(doLock);
}

void ZoneClientSession::sendMessage(BasePacket* msg) {
	ZoneClientSessionImplementation* _implementation = static_cast<ZoneClientSessionImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SENDMESSAGE__BASEPACKET_);
		method.addObjectParameter(msg);

		method.executeWithVoidReturn();
	} else
		_implementation->sendMessage(msg);
}

void ZoneClientSession::balancePacketCheckupTime() {
	ZoneClientSessionImplementation* _implementation = static_cast<ZoneClientSessionImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_BALANCEPACKETCHECKUPTIME__);

		method.executeWithVoidReturn();
	} else
		_implementation->balancePacketCheckupTime();
}

void ZoneClientSession::resetPacketCheckupTime() {
	ZoneClientSessionImplementation* _implementation = static_cast<ZoneClientSessionImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_RESETPACKETCHECKUPTIME__);

		method.executeWithVoidReturn();
	} else
		_implementation->resetPacketCheckupTime();
}

void ZoneClientSession::closeConnection(bool lockPlayer, bool doLock) {
	ZoneClientSessionImplementation* _implementation = static_cast<ZoneClientSessionImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CLOSECONNECTION__BOOL_BOOL_);
		method.addBooleanParameter(lockPlayer);
		method.addBooleanParameter(doLock);

		method.executeWithVoidReturn();
	} else
		_implementation->closeConnection(lockPlayer, doLock);
}

void ZoneClientSession::info(const String& msg, bool force) {
	ZoneClientSessionImplementation* _implementation = static_cast<ZoneClientSessionImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_INFO__STRING_BOOL_);
		method.addAsciiParameter(msg);
		method.addBooleanParameter(force);

		method.executeWithVoidReturn();
	} else
		_implementation->info(msg, force);
}

void ZoneClientSession::error(const String& msg) {
	ZoneClientSessionImplementation* _implementation = static_cast<ZoneClientSessionImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ERROR__STRING_);
		method.addAsciiParameter(msg);

		method.executeWithVoidReturn();
	} else
		_implementation->error(msg);
}

String ZoneClientSession::getAddress() {
	ZoneClientSessionImplementation* _implementation = static_cast<ZoneClientSessionImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETADDRESS__);

		method.executeWithAsciiReturn(_return_getAddress);
		return _return_getAddress;
	} else
		return _implementation->getAddress();
}

void ZoneClientSession::setPlayer(SceneObject* playerCreature) {
	ZoneClientSessionImplementation* _implementation = static_cast<ZoneClientSessionImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETPLAYER__SCENEOBJECT_);
		method.addObjectParameter(playerCreature);

		method.executeWithVoidReturn();
	} else
		_implementation->setPlayer(playerCreature);
}

void ZoneClientSession::setSessionID(unsigned int id) {
	ZoneClientSessionImplementation* _implementation = static_cast<ZoneClientSessionImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETSESSIONID__INT_);
		method.addUnsignedIntParameter(id);

		method.executeWithVoidReturn();
	} else
		_implementation->setSessionID(id);
}

void ZoneClientSession::setAccountID(unsigned int acc) {
	ZoneClientSessionImplementation* _implementation = static_cast<ZoneClientSessionImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETACCOUNTID__INT_);
		method.addUnsignedIntParameter(acc);

		method.executeWithVoidReturn();
	} else
		_implementation->setAccountID(acc);
}

int ZoneClientSession::getCommandCount() {
	ZoneClientSessionImplementation* _implementation = static_cast<ZoneClientSessionImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETCOMMANDCOUNT__);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->getCommandCount();
}

void ZoneClientSession::increaseCommandCount() {
	ZoneClientSessionImplementation* _implementation = static_cast<ZoneClientSessionImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_INCREASECOMMANDCOUNT__);

		method.executeWithVoidReturn();
	} else
		_implementation->increaseCommandCount();
}

void ZoneClientSession::resetCommandCount() {
	ZoneClientSessionImplementation* _implementation = static_cast<ZoneClientSessionImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_RESETCOMMANDCOUNT__);

		method.executeWithVoidReturn();
	} else
		_implementation->resetCommandCount();
}

Time* ZoneClientSession::getCommandSpamCooldown() {
	ZoneClientSessionImplementation* _implementation = static_cast<ZoneClientSessionImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->getCommandSpamCooldown();
}

BaseClientProxy* ZoneClientSession::getSession() {
	ZoneClientSessionImplementation* _implementation = static_cast<ZoneClientSessionImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->getSession();
}

SceneObject* ZoneClientSession::getPlayer() {
	ZoneClientSessionImplementation* _implementation = static_cast<ZoneClientSessionImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETPLAYER__);

		return static_cast<SceneObject*>(method.executeWithObjectReturn());
	} else
		return _implementation->getPlayer();
}

unsigned int ZoneClientSession::getSessionID() {
	ZoneClientSessionImplementation* _implementation = static_cast<ZoneClientSessionImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETSESSIONID__);

		return method.executeWithUnsignedIntReturn();
	} else
		return _implementation->getSessionID();
}

unsigned int ZoneClientSession::getAccountID() {
	ZoneClientSessionImplementation* _implementation = static_cast<ZoneClientSessionImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETACCOUNTID__);

		return method.executeWithUnsignedIntReturn();
	} else
		return _implementation->getAccountID();
}

bool ZoneClientSession::hasCharacter(unsigned long long cid) {
	ZoneClientSessionImplementation* _implementation = static_cast<ZoneClientSessionImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_HASCHARACTER__LONG_);
		method.addUnsignedLongParameter(cid);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->hasCharacter(cid);
}

void ZoneClientSession::addCharacter(unsigned long long cid) {
	ZoneClientSessionImplementation* _implementation = static_cast<ZoneClientSessionImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ADDCHARACTER__LONG_);
		method.addUnsignedLongParameter(cid);

		method.executeWithVoidReturn();
	} else
		_implementation->addCharacter(cid);
}

void ZoneClientSession::resetCharacters() {
	ZoneClientSessionImplementation* _implementation = static_cast<ZoneClientSessionImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_RESETCHARACTERS__);

		method.executeWithVoidReturn();
	} else
		_implementation->resetCharacters();
}

DistributedObjectServant* ZoneClientSession::_getImplementation() {

	_updated = true;
	return _impl;
}

void ZoneClientSession::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	ZoneClientSessionImplementation
 */

ZoneClientSessionImplementation::ZoneClientSessionImplementation(DummyConstructorParameter* param) : ManagedObjectImplementation(param) {
	_initializeImplementation();
}


ZoneClientSessionImplementation::~ZoneClientSessionImplementation() {
}


void ZoneClientSessionImplementation::finalize() {
}

void ZoneClientSessionImplementation::_initializeImplementation() {
	_setClassHelper(ZoneClientSessionHelper::instance());

	_this = NULL;

	_serializationHelperMethod();
}

void ZoneClientSessionImplementation::_setStub(DistributedObjectStub* stub) {
	_this = static_cast<ZoneClientSession*>(stub);
	ManagedObjectImplementation::_setStub(stub);
}

DistributedObjectStub* ZoneClientSessionImplementation::_getStub() {
	return _this;
}

ZoneClientSessionImplementation::operator const ZoneClientSession*() {
	return _this;
}

void ZoneClientSessionImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void ZoneClientSessionImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void ZoneClientSessionImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void ZoneClientSessionImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void ZoneClientSessionImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void ZoneClientSessionImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void ZoneClientSessionImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void ZoneClientSessionImplementation::_serializationHelperMethod() {
	ManagedObjectImplementation::_serializationHelperMethod();

	_setClassName("ZoneClientSession");

}

void ZoneClientSessionImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint32 _varSize = stream->readInt();

		int _currentOffset = stream->getOffset();

		if(ZoneClientSessionImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool ZoneClientSessionImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (ManagedObjectImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "ZoneClientSession.characters") {
		TypeInfo<HashSet<unsigned long long> >::parseFromBinaryStream(&characters, stream);
		return true;
	}

	if (_name == "ZoneClientSession.player") {
		TypeInfo<ManagedWeakReference<SceneObject* > >::parseFromBinaryStream(&player, stream);
		return true;
	}

	if (_name == "ZoneClientSession.sessionID") {
		TypeInfo<unsigned int >::parseFromBinaryStream(&sessionID, stream);
		return true;
	}

	if (_name == "ZoneClientSession.accountID") {
		TypeInfo<unsigned int >::parseFromBinaryStream(&accountID, stream);
		return true;
	}

	if (_name == "ZoneClientSession.disconnecting") {
		TypeInfo<bool >::parseFromBinaryStream(&disconnecting, stream);
		return true;
	}

	if (_name == "ZoneClientSession.commandSpamCooldown") {
		TypeInfo<Time >::parseFromBinaryStream(&commandSpamCooldown, stream);
		return true;
	}

	if (_name == "ZoneClientSession.commandCount") {
		TypeInfo<int >::parseFromBinaryStream(&commandCount, stream);
		return true;
	}


	return false;
}

void ZoneClientSessionImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = ZoneClientSessionImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int ZoneClientSessionImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	int _count = ManagedObjectImplementation::writeObjectMembers(stream);

	String _name;
	int _offset;
	uint32 _totalSize;
	_name = "ZoneClientSession.characters";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<HashSet<unsigned long long> >::toBinaryStream(&characters, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);

	_name = "ZoneClientSession.player";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<ManagedWeakReference<SceneObject* > >::toBinaryStream(&player, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);

	_name = "ZoneClientSession.sessionID";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<unsigned int >::toBinaryStream(&sessionID, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);

	_name = "ZoneClientSession.accountID";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<unsigned int >::toBinaryStream(&accountID, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);

	_name = "ZoneClientSession.disconnecting";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<bool >::toBinaryStream(&disconnecting, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);

	_name = "ZoneClientSession.commandSpamCooldown";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<Time >::toBinaryStream(&commandSpamCooldown, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);

	_name = "ZoneClientSession.commandCount";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<int >::toBinaryStream(&commandCount, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);


	return _count + 7;
}

void ZoneClientSessionImplementation::setPlayer(SceneObject* playerCreature) {
	// server/zone/ZoneClientSession.idl():  		player 
	if (playerCreature != player){
	// server/zone/ZoneClientSession.idl():  		}
	if (playerCreature == NULL && player != NULL){
	// server/zone/ZoneClientSession.idl():  				ZoneServer zoneServer = player.getZoneServer();
	ZoneServer* zoneServer = player->getZoneServer();
	// server/zone/ZoneClientSession.idl():  			}
	if (zoneServer != NULL)	// server/zone/ZoneClientSession.idl():  					zoneServer.decreaseOnlinePlayers();
	zoneServer->decreaseOnlinePlayers();
}

	else 	// server/zone/ZoneClientSession.idl():  		}
	if (playerCreature != player){
	// server/zone/ZoneClientSession.idl():  				ZoneServer zoneServer = playerCreature.getZoneServer();
	ZoneServer* zoneServer = playerCreature->getZoneServer();
	// server/zone/ZoneClientSession.idl():  			}
	if (zoneServer != NULL)	// server/zone/ZoneClientSession.idl():  					zoneServer.increaseOnlinePlayers();
	zoneServer->increaseOnlinePlayers();
}
}
	// server/zone/ZoneClientSession.idl():  		player = playerCreature;
	player = playerCreature;
}

void ZoneClientSessionImplementation::setSessionID(unsigned int id) {
	// server/zone/ZoneClientSession.idl():  		sessionID = id;
	sessionID = id;
}

void ZoneClientSessionImplementation::setAccountID(unsigned int acc) {
	// server/zone/ZoneClientSession.idl():  		accountID = acc;
	accountID = acc;
}

int ZoneClientSessionImplementation::getCommandCount() {
	// server/zone/ZoneClientSession.idl():  		return commandCount;
	return commandCount;
}

void ZoneClientSessionImplementation::increaseCommandCount() {
	// server/zone/ZoneClientSession.idl():  		commandCount = commandCount + 1;
	commandCount = commandCount + 1;
}

void ZoneClientSessionImplementation::resetCommandCount() {
	// server/zone/ZoneClientSession.idl():  		commandCount = 0;
	commandCount = 0;
}

Time* ZoneClientSessionImplementation::getCommandSpamCooldown() {
	// server/zone/ZoneClientSession.idl():  		return commandSpamCooldown;
	return (&commandSpamCooldown);
}

SceneObject* ZoneClientSessionImplementation::getPlayer() {
	// server/zone/ZoneClientSession.idl():  		return player;
	return player;
}

unsigned int ZoneClientSessionImplementation::getSessionID() {
	// server/zone/ZoneClientSession.idl():  		return sessionID;
	return sessionID;
}

unsigned int ZoneClientSessionImplementation::getAccountID() {
	// server/zone/ZoneClientSession.idl():  		return accountID;
	return accountID;
	// server/zone/ZoneClientSession.idl():  		return accountID;;
}

bool ZoneClientSessionImplementation::hasCharacter(unsigned long long cid) {
	// server/zone/ZoneClientSession.idl():  		return characters.contains(cid);
	return (&characters)->contains(cid);
}

void ZoneClientSessionImplementation::addCharacter(unsigned long long cid) {
	// server/zone/ZoneClientSession.idl():  		characters.add(cid);
	(&characters)->add(cid);
}

void ZoneClientSessionImplementation::resetCharacters() {
	// server/zone/ZoneClientSession.idl():  		characters.removeAll();
	(&characters)->removeAll();
}

/*
 *	ZoneClientSessionAdapter
 */


#include "engine/orb/messages/InvokeMethodMessage.h"


ZoneClientSessionAdapter::ZoneClientSessionAdapter(ZoneClientSession* obj) : ManagedObjectAdapter(obj) {
}

void ZoneClientSessionAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	DOBMessage* resp = inv->getInvocationMessage();

	switch (methid) {
	case RPC_DISCONNECT__:
		disconnect();
		break;
	case RPC_DISCONNECT__BOOL_:
		disconnect(inv->getBooleanParameter());
		break;
	case RPC_SENDMESSAGE__BASEPACKET_:
		sendMessage(static_cast<BasePacket*>(inv->getObjectParameter()));
		break;
	case RPC_BALANCEPACKETCHECKUPTIME__:
		balancePacketCheckupTime();
		break;
	case RPC_RESETPACKETCHECKUPTIME__:
		resetPacketCheckupTime();
		break;
	case RPC_CLOSECONNECTION__BOOL_BOOL_:
		closeConnection(inv->getBooleanParameter(), inv->getBooleanParameter());
		break;
	case RPC_INFO__STRING_BOOL_:
		info(inv->getAsciiParameter(_param0_info__String_bool_), inv->getBooleanParameter());
		break;
	case RPC_ERROR__STRING_:
		error(inv->getAsciiParameter(_param0_error__String_));
		break;
	case RPC_GETADDRESS__:
		resp->insertAscii(getAddress());
		break;
	case RPC_SETPLAYER__SCENEOBJECT_:
		setPlayer(static_cast<SceneObject*>(inv->getObjectParameter()));
		break;
	case RPC_SETSESSIONID__INT_:
		setSessionID(inv->getUnsignedIntParameter());
		break;
	case RPC_SETACCOUNTID__INT_:
		setAccountID(inv->getUnsignedIntParameter());
		break;
	case RPC_GETCOMMANDCOUNT__:
		resp->insertSignedInt(getCommandCount());
		break;
	case RPC_INCREASECOMMANDCOUNT__:
		increaseCommandCount();
		break;
	case RPC_RESETCOMMANDCOUNT__:
		resetCommandCount();
		break;
	case RPC_GETPLAYER__:
		resp->insertLong(getPlayer()->_getObjectID());
		break;
	case RPC_GETSESSIONID__:
		resp->insertInt(getSessionID());
		break;
	case RPC_GETACCOUNTID__:
		resp->insertInt(getAccountID());
		break;
	case RPC_HASCHARACTER__LONG_:
		resp->insertBoolean(hasCharacter(inv->getUnsignedLongParameter()));
		break;
	case RPC_ADDCHARACTER__LONG_:
		addCharacter(inv->getUnsignedLongParameter());
		break;
	case RPC_RESETCHARACTERS__:
		resetCharacters();
		break;
	default:
		throw Exception("Method does not exists");
	}
}

void ZoneClientSessionAdapter::disconnect() {
	(static_cast<ZoneClientSession*>(stub))->disconnect();
}

void ZoneClientSessionAdapter::disconnect(bool doLock) {
	(static_cast<ZoneClientSession*>(stub))->disconnect(doLock);
}

void ZoneClientSessionAdapter::sendMessage(BasePacket* msg) {
	(static_cast<ZoneClientSession*>(stub))->sendMessage(msg);
}

void ZoneClientSessionAdapter::balancePacketCheckupTime() {
	(static_cast<ZoneClientSession*>(stub))->balancePacketCheckupTime();
}

void ZoneClientSessionAdapter::resetPacketCheckupTime() {
	(static_cast<ZoneClientSession*>(stub))->resetPacketCheckupTime();
}

void ZoneClientSessionAdapter::closeConnection(bool lockPlayer, bool doLock) {
	(static_cast<ZoneClientSession*>(stub))->closeConnection(lockPlayer, doLock);
}

void ZoneClientSessionAdapter::info(const String& msg, bool force) {
	(static_cast<ZoneClientSession*>(stub))->info(msg, force);
}

void ZoneClientSessionAdapter::error(const String& msg) {
	(static_cast<ZoneClientSession*>(stub))->error(msg);
}

String ZoneClientSessionAdapter::getAddress() {
	return (static_cast<ZoneClientSession*>(stub))->getAddress();
}

void ZoneClientSessionAdapter::setPlayer(SceneObject* playerCreature) {
	(static_cast<ZoneClientSession*>(stub))->setPlayer(playerCreature);
}

void ZoneClientSessionAdapter::setSessionID(unsigned int id) {
	(static_cast<ZoneClientSession*>(stub))->setSessionID(id);
}

void ZoneClientSessionAdapter::setAccountID(unsigned int acc) {
	(static_cast<ZoneClientSession*>(stub))->setAccountID(acc);
}

int ZoneClientSessionAdapter::getCommandCount() {
	return (static_cast<ZoneClientSession*>(stub))->getCommandCount();
}

void ZoneClientSessionAdapter::increaseCommandCount() {
	(static_cast<ZoneClientSession*>(stub))->increaseCommandCount();
}

void ZoneClientSessionAdapter::resetCommandCount() {
	(static_cast<ZoneClientSession*>(stub))->resetCommandCount();
}

SceneObject* ZoneClientSessionAdapter::getPlayer() {
	return (static_cast<ZoneClientSession*>(stub))->getPlayer();
}

unsigned int ZoneClientSessionAdapter::getSessionID() {
	return (static_cast<ZoneClientSession*>(stub))->getSessionID();
}

unsigned int ZoneClientSessionAdapter::getAccountID() {
	return (static_cast<ZoneClientSession*>(stub))->getAccountID();
}

bool ZoneClientSessionAdapter::hasCharacter(unsigned long long cid) {
	return (static_cast<ZoneClientSession*>(stub))->hasCharacter(cid);
}

void ZoneClientSessionAdapter::addCharacter(unsigned long long cid) {
	(static_cast<ZoneClientSession*>(stub))->addCharacter(cid);
}

void ZoneClientSessionAdapter::resetCharacters() {
	(static_cast<ZoneClientSession*>(stub))->resetCharacters();
}

/*
 *	ZoneClientSessionHelper
 */

ZoneClientSessionHelper* ZoneClientSessionHelper::staticInitializer = ZoneClientSessionHelper::instance();

ZoneClientSessionHelper::ZoneClientSessionHelper() {
	className = "ZoneClientSession";

	Core::getObjectBroker()->registerClass(className, this);
}

void ZoneClientSessionHelper::finalizeHelper() {
	ZoneClientSessionHelper::finalize();
}

DistributedObject* ZoneClientSessionHelper::instantiateObject() {
	return new ZoneClientSession(DummyConstructorParameter::instance());
}

DistributedObjectServant* ZoneClientSessionHelper::instantiateServant() {
	return new ZoneClientSessionImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* ZoneClientSessionHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new ZoneClientSessionAdapter(static_cast<ZoneClientSession*>(obj));

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

