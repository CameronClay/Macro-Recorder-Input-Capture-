#pragma once

template<typename Rtn, typename... Args>
struct FPHelper
{
	typedef Rtn(*Function)(Args...);
};

template<typename Rtn, typename O, typename... Args>
struct FPMHelper
{
	typedef Rtn(O::*Function)(Args...);
};

template<typename Rtn, typename O, typename... Args>
struct FPMHelperConst
{
	typedef Rtn(O::*Function)(Args...) const;
};

template<typename Rtn, typename... Args>
using PFunc = typename FPHelper<Rtn, Args...>::Function;

template<typename Rtn, typename O, typename... Args>
using PMFunc = typename FPMHelper<Rtn, O, Args...>::Function;

template<typename Rtn, typename O, typename... Args>
using PMFuncC = typename FPMHelperConst<Rtn, O, Args...>::Function;