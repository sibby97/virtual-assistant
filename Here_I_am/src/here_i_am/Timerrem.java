/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package here_i_am;
import java.util.TimerTask;
import java.util.logging.Level;
import java.util.logging.Logger;
/**
 *
 * @author sibby
 */
public class Timerrem extends TimerTask{
    public String username;
    public String name;
    public void setusername(String u){
        this.username = u;
    }
    public void setname(String n){
        this.name = n;
    }
    @Override
    public void run(){
        try {
            Reminder r = new Reminder(username,name);
            //r.setusername(username);
            //r.setname(name);  
            r.setVisible(true);
        } catch (Exception ex) {
            Logger.getLogger(Timerrem.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
