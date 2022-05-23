
#include <hook.h>
#include <mod.h>
#include <logger.h>
#include <symbol.h>
#include <innercore_callbacks.h>
#include <nativejs.h>
#include <vtable.h>
#include <stl/string>
#define stl std::__ndk1



class CoreUtility : public Module {
public:
	CoreUtility(const char* id): Module(id) {};
	static jclass callback_class;

	virtual void initialize() {	
		Logger::debug("Sample Native Mod", "Initialize core");
		DLHandleManager::initializeHandle("libminecraftpe.so", "mcpe");
		Logger::flush();

    }
};





MAIN {
	Module* main_module = new CoreUtility("sample_mod");




}	

