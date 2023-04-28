#include "Task.hpp"

using namespace transformer;

Task::Task(std::string const& name, TaskCore::TaskState initial_state)
    : TaskBase(name, initial_state)
{
    _configuration_state.keepLastWrittenValue(true);
}

Task::Task(std::string const& name, RTT::ExecutionEngine* engine, TaskCore::TaskState initial_state)
    : TaskBase(name, engine, initial_state)
{
    _configuration_state.keepLastWrittenValue(true);
}

Task::~Task()
{
}

void Task::setConfiguration(::transformer::ConfigurationState const& configuration)
{
    _configuration_state.write(configuration);
}

bool Task::startHook()
{
     if (! TaskBase::startHook())
         return false;
     setConfiguration(_configuration.get());
     return true;
}
