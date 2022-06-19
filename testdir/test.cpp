/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:51:41 by hseong            #+#    #+#             */
/*   Updated: 2022/04/28 20:39:46 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <typeinfo>

class Test
{
	private:
		int	i;
		std::string s;
	public:
		Test();
		~Test();
};

Test::Test(void)
{
	i = 42;
	s = "42\n";
}

Test::~Test(void)
{
}

int main(void)
{
	Test	*a;
	Test	*b[5];
	Test	c[4];
	Test	d;
	//	Test	f[2][3];
	//	int 	**((*g)[2]);

	std::cout << typeid(a).name() << std::endl;
	std::cout << typeid(b).name() << std::endl;
	std::cout << typeid(c).name() << std::endl;
	std::cout << typeid(d).name() << std::endl;
	std::cout << typeid(&c).name() << std::endl;
	return (0);
}
