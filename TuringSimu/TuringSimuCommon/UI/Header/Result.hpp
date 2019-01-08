#ifndef TM_RESULT
#define TM_RESULT

template<class T> class Result
{
public:
		const T Value;
		const bool Failure;
		Result(const T& value, bool failure)
			: Value(value),
			  Failure(failure)
		{
		}

		Result() : Failure(true) {};
};
#endif // TM_RESULT
