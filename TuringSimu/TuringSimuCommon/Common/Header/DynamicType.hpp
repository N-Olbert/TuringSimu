#pragma once
#ifndef TM_DYNAMICTYPE
#define TM_DYNAMICTYPE
namespace ts_common
{
	/**
	 * \brief Basically a managed void pointer.
	 */
	class DynamicType
	{
		protected:

			/**
			 * \brief Gets the carried value as void pointer.
			 * \return The carried value. Can be anything.
			 */
			virtual const void* GetValue() const = 0;

		public:

			virtual ~DynamicType() = default;

			/**
			 * \brief Retrieves the carried value as the given type.
			 * \n Note: This carried value isnt reinterpreted(!), so it must be a real instance of the requested type
			 * \return The carried value as requested type
			 */
			template<class T> const T& As() const
			{
				return *(static_cast<const T*>(GetValue()));
			}
	};
}
#endif // TM_DYNAMICTYPE
