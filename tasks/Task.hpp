#ifndef TRANSFORMER_TASK_TASK_HPP
#define TRANSFORMER_TASK_TASK_HPP

#include "transformer/TaskBase.hpp"

namespace transformer
{
    class Task : public TaskBase
    {
    friend class TaskBase;
    protected:
        virtual void setConfiguration(::transformer::ConfigurationState const & configuration);

    public:
        Task(std::string const& name = "transformer::Task", TaskCore::TaskState initial_state = Stopped);
        Task(std::string const& name, RTT::ExecutionEngine* engine, TaskCore::TaskState initial_state = Stopped);
        ~Task();

        bool startHook();
    };
}

#endif
