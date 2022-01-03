#include"Student.h"

int main()
{
	Student st;
	cout << st.Id() << "-" << st.Fullname() << "-" << st.Email() << "\n";
	cout << st.Birthday().toString() << "-" << st.Address() << "-" << st.Tel() << "\n";
	st.SetId("18125001");
	st.SetFulname("NHTT");
	Date date;
	date.setDay(28);
	date.setMonth(8);
	date.setYear(2000);
	st.SetBirthday(date);
	st.SetAddress("HCM");
	st.SetEmail("nhk@gmail.com");
	st.SetTel("0374448338");
	cout << st.toString() << "\n";

	try
	{
		Date n(28, 8, 2000);
		Student norm("18125001", "NHTT", "nhk@gmail.com", n, "HCM", "0374448338");
		Date fail(29, 2, 2019);
		cout << "Time caused exception" << fail.toString() << endl;
	}
	catch (exception &ex)
	{
		cout << ex.what();
	}
	system("pause");
	return 0;
}