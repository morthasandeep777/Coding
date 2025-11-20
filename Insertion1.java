import java.sql.*;
public class Insertion1
{
	public static void main(String[] args) throws ClassNotFoundException,SQLException
	{
		Connection con=null;
		Statement st=null;
		int res=0;
		Class.forName("com.mysql.cj.jdbc.Driver");
			
		con = DriverManager.getConnection("jdbc:mysql://localhost:3306/Stud_info","root","");

		String query= "Insert si(Name,ID)values('Sandy',111)";
		st = con.createStatement();
		res=st.executeUpdate(query);
		if(res>0)
		{
			System.out.println("Inserted Successfully");
		}
		else
		{
			System.out.println("Insertion Failed");
		}
		con.close();
	}
}