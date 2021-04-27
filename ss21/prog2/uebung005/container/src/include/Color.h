#ifndef COLOR_H
#define COLOR_H
class Color{
	public:
		Color();
		Color(int r, int g, int b);
		int getRed() const;
		int getGreen() const;
		int getBlue() const;
		void setRed(int r);
		void setGreen(int g);
		void setBlue(int b);
		Color darken(int amount);
		Color lighten(int amount);
		Color averageWith(const Color& other) const;
		Color averageWith(const Color& other1, const Color& other2, const Color& other3) const;
		Color randomlyChange(int maxAmount) const;
		inline bool equals(const Color& other) const;

		static const Color nullColor;

	private:
		int red;
		int green;
		int blue;
};
#endif
