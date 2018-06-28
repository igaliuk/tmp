#ifndef TEXTURE_HPP
# define TEXTURE_HPP

# include "BestTanks.h"

class Texture {

	private:

		int				_type;
		int				_power;
		int				_passability;
		float			_speed;
		XYWay			_xyway;

	public:

		Texture(int const type, int const power, int const passability, float const speed, int const x, int const y);

		int				getType() const;
		int				getPower() const;
		int				getPassability() const;
		float			getSpeed() const;
		XYWay			&getXYWay();

		void			destroed();

		~Texture();
};

#endif