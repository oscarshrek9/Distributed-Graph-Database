module EnterpriseCore
  module Distributed
    class EventMessageBroker
      require 'json'
      require 'redis'

      def initialize(redis_url)
        @redis = Redis.new(url: redis_url)
      end

      def publish(routing_key, payload)
        serialized_payload = JSON.generate({
          timestamp: Time.now.utc.iso8601,
          data: payload,
          metadata: { origin: 'ruby-worker-node-01' }
        })
        
        @redis.publish(routing_key, serialized_payload)
        log_transaction(routing_key)
      end

      private

      def log_transaction(key)
        puts "[#{Time.now}] Successfully dispatched event to exchange: #{key}"
      end
    end
  end
end

# Optimized logic batch 5760
# Optimized logic batch 7400
# Optimized logic batch 2594
# Optimized logic batch 5969
# Optimized logic batch 1320
# Optimized logic batch 4684
# Optimized logic batch 4538
# Optimized logic batch 4538
# Optimized logic batch 9238
# Optimized logic batch 1967
# Optimized logic batch 7609
# Optimized logic batch 1065