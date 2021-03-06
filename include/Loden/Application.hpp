#ifndef LODEN_APPLICATION_HPP
#define LODEN_APPLICATION_HPP

#include "Loden/Common.hpp"
#include "Loden/Engine.hpp"
#include "SDL.h"

namespace Loden
{

/**
 * Loden Application class
 */	
class LODEN_CORE_EXPORT Application
{
public:
	virtual int main(int argc, const char **argv);
	
    const EnginePtr &getEngine() const;
    virtual void mainLoopQuit();

protected:
	virtual bool parseCommandLine(int argc, const char **argv);
	virtual bool initialize();
	virtual bool run();
	virtual bool shutdown();
	
	virtual bool enterMainLoop(float updateStep);
	virtual void pumpEvents();
	virtual void mainLoopUpdateStep(float updateDelta);
	virtual void mainLoopRenderStep();
    virtual void updateFpsDisplay(float fps);

    EnginePtr engine;

private:
	bool mainLoopQuit_;
};

} // End of namespace Loden

#define APPLICATION_ENTRY_POINT(applicationClass) \
int main(int argc, char *argv[]) { \
	applicationClass app; \
	return app.main(argc, (const char **)argv); \
} 

#endif //LODEN_APPLICATION_HPP
