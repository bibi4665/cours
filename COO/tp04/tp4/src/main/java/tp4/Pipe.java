package tp4;

import java.security.PublicKey;

import javax.crypto.spec.IvParameterSpec;

public class Pipe implements Tickeable {

    private int quantity;
    private IBucket a;
    private IBucket b;
    
    public Pipe(IBucket a, int q, IBucket b){
        this.a = a;
        this.quantity = q;
        this.b = b;
    }

    public void step(){
        b.remplit(a.vide(this.quantity));
    }

    @Override  
    public String toString (){
        return "cuve a = " + this.a +" quatity = "+this.quantity +" b = "+ this.b;
    }


}
