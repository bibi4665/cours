package tp4;

public class Bucket implements IBucket {

    protected int quantity;

    public Bucket(int q){
        this.quantity = q;
    }

    @Override
    public String toString(){
        return "Bucket " + "quantity = " + this.quantity;
    }

    @Override
    public void step(){

    }

    @Override 
    public int vide (int q){
        if(this.quantity < q){
            q = this.quantity;
            this.quantity = 0;
            this.step();
            return q;
        }
        else{
            this.quantity -= q;
            this.step();
            return q;
        }
    }

    @Override 
    public void remplit(int q){
        this.quantity += q;
        this.step();
    }

}

