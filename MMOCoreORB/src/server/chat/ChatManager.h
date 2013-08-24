/*
 *	server/chat/ChatManager.h generated by engine3 IDL compiler 0.60
 */

#ifndef CHATMANAGER_H_
#define CHATMANAGER_H_

#include "engine/core/Core.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace server {
namespace zone {

class ZoneServer;

} // namespace zone
} // namespace server

using namespace server::zone;

namespace server {
namespace chat {
namespace room {

class ChatRoom;

} // namespace room
} // namespace chat
} // namespace server

using namespace server::chat::room;

namespace server {
namespace chat {
namespace room {

class ChatRoomMap;

} // namespace room
} // namespace chat
} // namespace server

using namespace server::chat::room;

namespace server {
namespace zone {
namespace objects {
namespace creature {

class CreatureObject;

} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature;

namespace server {
namespace zone {
namespace managers {
namespace player {

class PlayerMap;

} // namespace player
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::player;

namespace server {
namespace zone {
namespace managers {
namespace player {

class PlayerManager;

} // namespace player
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::player;

namespace server {
namespace zone {
namespace objects {
namespace creature {

class CreatureObject;

} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature;

namespace server {
namespace zone {
namespace packets {
namespace chat {

class ChatRoomList;

} // namespace chat
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::chat;

namespace server {
namespace zone {
namespace packets {
namespace chat {

class ChatInstantMessageToCharacter;

} // namespace chat
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::chat;

namespace server {
namespace zone {
namespace managers {
namespace objectcontroller {

class ObjectController;

} // namespace objectcontroller
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::objectcontroller;

namespace server {
namespace zone {
namespace objects {
namespace waypoint {

class WaypointObject;

} // namespace waypoint
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::waypoint;

#include "server/chat/StringIdChatParameter.h"

#include "server/chat/WaypointChatParameter.h"

#include "server/chat/StringIdChatParameterVector.h"

#include "server/chat/WaypointChatParameterVector.h"

#include "engine/core/ManagedService.h"

#include "engine/service/proto/BaseMessage.h"

#include "system/util/VectorMap.h"

#include "system/util/HashTable.h"

#include "engine/log/Logger.h"

namespace server {
namespace chat {

class ChatManager : public ManagedService {
public:
	static const int IM_SUCCESS = 0x00;

	static const int IM_OFFLINE = 0x04;

	static const int IM_IGNORED = 0x09;

	static const int IM_TOOLONG = 0x10;

	static const int IM_MAXSIZE = 255;

	static const int PM_MAXSIZE = 4000;

	ChatManager(ZoneServer* serv, int initsize);

	void initiateRooms();

	void destroyRooms();

	ChatRoom* createRoom(const String& roomName, ChatRoom* parent = NULL);

	void addRoom(ChatRoom* channel);

	void removeRoom(ChatRoom* channel);

	void populateRoomListMessage(ChatRoom* channel, ChatRoomList* msg);

	void sendRoomList(CreatureObject* player);

	void addPlayer(CreatureObject* player);

	CreatureObject* getPlayer(const String& name);

	CreatureObject* removePlayer(const String& name);

	void broadcastMessage(BaseMessage* message);

	void broadcastMessage(CreatureObject* player, const UnicodeString& message, unsigned long long target = 0, unsigned int moodid = 0, unsigned int mood2 = 0);

	void handleSpatialChatInternalMessage(CreatureObject* player, const UnicodeString& args);

	void handleGroupChat(CreatureObject* player, const UnicodeString& message);

	void handleGuildChat(CreatureObject* player, const UnicodeString& message);

	void handlePlanetChat(CreatureObject* player, const UnicodeString& message);

	ChatRoom* createRoomByFullPath(const String& path);

	ChatRoom* getChatRoomByFullPath(const String& path);

	ChatRoom* getChatRoomByGamePath(ChatRoom* game, const String& path);

	void handleChatRoomMessage(CreatureObject* sender, const UnicodeString& message, unsigned int roomID, unsigned int counter);

	void handleChatEnterRoomById(CreatureObject* player, unsigned int counter, unsigned int roomID);

	void handleSocialInternalMessage(CreatureObject* sender, const UnicodeString& arguments);

	void handleChatInstantMessageToCharacter(ChatInstantMessageToCharacter* message);

	void destroyRoom(ChatRoom* room);

	ChatRoom* createGroupRoom(unsigned long long groupID, CreatureObject* creator);

	void loadMail(CreatureObject* player);

	void sendMail(const String& sendername, const UnicodeString& header, const UnicodeString& body, const String& name);

	int sendMail(const String& sendername, const UnicodeString& subject, StringIdChatParameter& body, const String& recipientName, WaypointObject* waypoint = NULL);

	int sendMail(const String& sendername, const UnicodeString& subject, const UnicodeString& body, const String& recipientName, StringIdChatParameterVector* stringIdParameters, WaypointChatParameterVector* waypointParameters);

	void handleRequestPersistentMsg(CreatureObject* player, unsigned int mailID);

	void deletePersistentMessage(CreatureObject* player, unsigned int mailID);

	void broadcastGalaxy(CreatureObject* player, const String& message);

	void broadcastGalaxy(const String& message, const String& faction);

	void setPlayerManager(PlayerManager* manager);

	ChatRoom* getChatRoom(unsigned int id);

	ChatRoom* getGameRoom(const String& game);

	unsigned int getNextRoomID();

	int getPlayerCount();

	PlayerMap* getPlayerMap();

	ChatRoom* getGuildRoom();

	ChatRoom* getGroupRoom();

	DistributedObjectServant* _getImplementation();
	DistributedObjectServant* _getImplementationForRead();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	ChatManager(DummyConstructorParameter* param);

	virtual ~ChatManager();

	friend class ChatManagerHelper;
};

} // namespace chat
} // namespace server

using namespace server::chat;

namespace server {
namespace chat {

class ChatManagerImplementation : public ManagedServiceImplementation, public Logger {
	ManagedReference<ZoneServer* > server;

	ManagedReference<PlayerManager* > playerManager;

	Reference<PlayerMap* > playerMap;

	VectorMap<String, ManagedReference<ChatRoom* > > gameRooms;

	ManagedReference<ChatRoom* > groupRoom;

	ManagedReference<ChatRoom* > guildRoom;

	Reference<ChatRoomMap* > roomMap;

	unsigned int roomID;

	bool mute;

public:
	static const int IM_SUCCESS = 0x00;

	static const int IM_OFFLINE = 0x04;

	static const int IM_IGNORED = 0x09;

	static const int IM_TOOLONG = 0x10;

	static const int IM_MAXSIZE = 255;

	static const int PM_MAXSIZE = 4000;

	ChatManagerImplementation(ZoneServer* serv, int initsize);

	ChatManagerImplementation(DummyConstructorParameter* param);

	void finalize();

	void initiateRooms();

	void destroyRooms();

	ChatRoom* createRoom(const String& roomName, ChatRoom* parent = NULL);

	void addRoom(ChatRoom* channel);

	void removeRoom(ChatRoom* channel);

	void populateRoomListMessage(ChatRoom* channel, ChatRoomList* msg);

	void sendRoomList(CreatureObject* player);

	void addPlayer(CreatureObject* player);

	CreatureObject* getPlayer(const String& name);

	CreatureObject* removePlayer(const String& name);

	void broadcastMessage(BaseMessage* message);

	void broadcastMessage(CreatureObject* player, const UnicodeString& message, unsigned long long target = 0, unsigned int moodid = 0, unsigned int mood2 = 0);

	void handleSpatialChatInternalMessage(CreatureObject* player, const UnicodeString& args);

	void handleGroupChat(CreatureObject* player, const UnicodeString& message);

	void handleGuildChat(CreatureObject* player, const UnicodeString& message);

	void handlePlanetChat(CreatureObject* player, const UnicodeString& message);

	ChatRoom* createRoomByFullPath(const String& path);

	ChatRoom* getChatRoomByFullPath(const String& path);

	ChatRoom* getChatRoomByGamePath(ChatRoom* game, const String& path);

	void handleChatRoomMessage(CreatureObject* sender, const UnicodeString& message, unsigned int roomID, unsigned int counter);

	void handleChatEnterRoomById(CreatureObject* player, unsigned int counter, unsigned int roomID);

	void handleSocialInternalMessage(CreatureObject* sender, const UnicodeString& arguments);

	void handleChatInstantMessageToCharacter(ChatInstantMessageToCharacter* message);

	void destroyRoom(ChatRoom* room);

	ChatRoom* createGroupRoom(unsigned long long groupID, CreatureObject* creator);

	void loadMail(CreatureObject* player);

	void sendMail(const String& sendername, const UnicodeString& header, const UnicodeString& body, const String& name);

	int sendMail(const String& sendername, const UnicodeString& subject, StringIdChatParameter& body, const String& recipientName, WaypointObject* waypoint = NULL);

	int sendMail(const String& sendername, const UnicodeString& subject, const UnicodeString& body, const String& recipientName, StringIdChatParameterVector* stringIdParameters, WaypointChatParameterVector* waypointParameters);

	void handleRequestPersistentMsg(CreatureObject* player, unsigned int mailID);

	void deletePersistentMessage(CreatureObject* player, unsigned int mailID);

	void broadcastGalaxy(CreatureObject* player, const String& message);

	void broadcastGalaxy(const String& message, const String& faction);

	void setPlayerManager(PlayerManager* manager);

	ChatRoom* getChatRoom(unsigned int id);

	ChatRoom* getGameRoom(const String& game);

	unsigned int getNextRoomID();

	int getPlayerCount();

	PlayerMap* getPlayerMap();

	ChatRoom* getGuildRoom();

	ChatRoom* getGroupRoom();

	WeakReference<ChatManager*> _this;

	operator const ChatManager*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~ChatManagerImplementation();

	void _initializeImplementation();

	void _setStub(DistributedObjectStub* stub);

	void lock(bool doLock = true);

	void lock(ManagedObject* obj);

	void rlock(bool doLock = true);

	void wlock(bool doLock = true);

	void wlock(ManagedObject* obj);

	void unlock(bool doLock = true);

	void runlock(bool doLock = true);

	void _serializationHelperMethod();
	bool readObjectMember(ObjectInputStream* stream, const uint32& nameHashCode);
	int writeObjectMembers(ObjectOutputStream* stream);

	friend class ChatManager;
};

class ChatManagerAdapter : public ManagedServiceAdapter {
public:
	ChatManagerAdapter(ChatManager* impl);

	void invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void finalize();

	void initiateRooms();

	void destroyRooms();

	ChatRoom* createRoom(const String& roomName, ChatRoom* parent);

	void addRoom(ChatRoom* channel);

	void removeRoom(ChatRoom* channel);

	void populateRoomListMessage(ChatRoom* channel, ChatRoomList* msg);

	void sendRoomList(CreatureObject* player);

	void addPlayer(CreatureObject* player);

	CreatureObject* getPlayer(const String& name);

	CreatureObject* removePlayer(const String& name);

	void broadcastMessage(BaseMessage* message);

	void broadcastMessage(CreatureObject* player, const UnicodeString& message, unsigned long long target, unsigned int moodid, unsigned int mood2);

	void handleSpatialChatInternalMessage(CreatureObject* player, const UnicodeString& args);

	void handleGroupChat(CreatureObject* player, const UnicodeString& message);

	void handleGuildChat(CreatureObject* player, const UnicodeString& message);

	void handlePlanetChat(CreatureObject* player, const UnicodeString& message);

	ChatRoom* createRoomByFullPath(const String& path);

	ChatRoom* getChatRoomByFullPath(const String& path);

	ChatRoom* getChatRoomByGamePath(ChatRoom* game, const String& path);

	void handleChatRoomMessage(CreatureObject* sender, const UnicodeString& message, unsigned int roomID, unsigned int counter);

	void handleChatEnterRoomById(CreatureObject* player, unsigned int counter, unsigned int roomID);

	void handleSocialInternalMessage(CreatureObject* sender, const UnicodeString& arguments);

	void destroyRoom(ChatRoom* room);

	ChatRoom* createGroupRoom(unsigned long long groupID, CreatureObject* creator);

	void loadMail(CreatureObject* player);

	void sendMail(const String& sendername, const UnicodeString& header, const UnicodeString& body, const String& name);

	void handleRequestPersistentMsg(CreatureObject* player, unsigned int mailID);

	void deletePersistentMessage(CreatureObject* player, unsigned int mailID);

	void broadcastGalaxy(CreatureObject* player, const String& message);

	void broadcastGalaxy(const String& message, const String& faction);

	void setPlayerManager(PlayerManager* manager);

	ChatRoom* getChatRoom(unsigned int id);

	ChatRoom* getGameRoom(const String& game);

	unsigned int getNextRoomID();

	int getPlayerCount();

	ChatRoom* getGuildRoom();

	ChatRoom* getGroupRoom();

};

class ChatManagerHelper : public DistributedObjectClassHelper, public Singleton<ChatManagerHelper> {
	static ChatManagerHelper* staticInitializer;

public:
	ChatManagerHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<ChatManagerHelper>;
};

} // namespace chat
} // namespace server

using namespace server::chat;

#endif /*CHATMANAGER_H_*/
